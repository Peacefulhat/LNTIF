#ifndef TURNSTILE_H
#define TURNSTILE_H

#include <stdio.h>

typedef unsigned int uint64;

typedef enum{
    LOCKED,
    UNLOCKED
}States;

typedef enum{
    PUSH,
    COIN
}Events;

#define EVENTS_COUNT 2
#define STATES_COUNT 2

const uint64 FSM[STATES_COUNT][EVENTS_COUNT] = {
    {LOCKED,UNLOCKED},
    {LOCKED,UNLOCKED}
};

uint64 next_state(char c, States *s, Events *e);
void print_state(uint64 state_index);
void turnstile();

#endif //TURNSTILE_H

#ifdef TURNSTILE_IMPLEMENTATION

uint64 next_state(char c, States *s, Events *e)
{
    switch(c)
    {
        case 'c':{
            *e=COIN;
        }
        break;
        
        case 'p': {
            *e=PUSH;
        }
        break;
        
        default:{
            return 3;
        }
    }
    
    *s=FSM[*s][*e];
    return FSM[*s][*e];
}


void print_state(uint64 current_state)
{
    if(current_state == 0){
        printf("LOCKED\n");
    }else if(current_state == 1){
        printf("UNLOCKED\n");
    }else{
        printf("NOT A VALID STATE\n");
    }
    
}


void turnstile()
{
    // inital state;
    States s = LOCKED;
    Events e = PUSH;
    char event[10];
    printf("Current State:: ");
    print_state((uint64)s);
    while(event[0]!='q')
    {
        printf(">");
        scanf("%s",event);
        uint64 result = next_state(event[0],&s,&e);
        printf("Current State :: ");
        print_state(result);
    }
}

#endif// TURNSTILE_IMPLEMENTATION
