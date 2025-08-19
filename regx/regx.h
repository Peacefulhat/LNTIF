#ifndef REGX_H
#define REGX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATE_COUNT 127
typedef unsigned char uchar;
typedef unsigned int uint64;
typedef struct
{
    uint64 max_state;
    uchar* buffer;
    
}FSM;

void alloc_buffer(FSM *s, uint64 max_state);
void fill_range(uchar* begin, uint64 size, uchar state);
void print_state(FSM s);
#endif//  REGX_H

#ifdef REGX_IMPLEMENTATION

void alloc_buffer(FSM *s, uint64 max_state)
{
    s->max_state = max_state;
    s->buffer = malloc(sizeof(uchar)*max_state);
    memset(s->buffer,65,sizeof(uchar)*max_state);
}    

void print_state(FSM s)
{
    printf("{");
    for(uint64 i=0; i<s.max_state; ++i)
    {
        printf("%c,", s.buffer[i]);
    }
    printf("}");
}

void fill_range(uchar* begin, uint64 size, uchar state)
{
    for(uint64 i = 0; i < size; ++i)
    {
       begin[i]=state;
    }
}

#endif //REGX_IMPLEMENTATION
