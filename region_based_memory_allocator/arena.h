#ifndef ARENA_H
#define ARENA_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<assert.h>

#ifdef PMATH
#include"pmath.h"
#endif

#define A_ASSERT assert
#define ARENA_REGION_CAPACITY 10 // no of nodes in arena

typedef enum {
  CHAR=0,
  INT,
  FLOAT,
  DOUBLE,
  UINT
}Types;


 struct Region{
  size_t count;
  size_t capacity;
  Types type;
  struct Region *next;
  void*mem_region;
};

typedef struct Region Region;

typedef struct{
  Region*begin,*end;
  size_t region_count;
  size_t region_capacity;
}Arena;

Arena* alloc_arena();
Region* alloc_region(size_t capacity,Types t);


#endif// ARENA_H

#ifdef ARENA_IMP

// alloated area
Arena* alloc_arena(){
  Arena*alloc_space=malloc(sizeof(Arena));
  A_ASSERT(alloc_space!=NULL);
  alloc_space->begin=NULL;
  alloc_space->end=NULL;
  alloc_space->region_count=0;
  alloc_space->region_capacity=ARENA_REGION_CAPACITY;
  return alloc_space;
}

size_t sizeof_types(Types type){
  switch(type){
  case CHAR:
    {
    return sizeof(char);
    }
    break;
    
      case INT:
    {
    return sizeof(int);
    }
    break;
    
  case FLOAT:
    {
    return sizeof(float);
    }
    break;
    
    case DOUBLE:
    {
    return sizeof(double);
    }
    break;
    
  case UINT:
    {
    return sizeof(unsigned int);
    }
    break;
  }
  return -1;// indiacting not a valid type
}

Region* alloc_region(size_t capacity,Types t){
  
  Region*region_block=malloc(sizeof(Region));
  A_ASSERT(region_block!=NULL);
  region_block->mem_region=malloc(sizeof_types(t)*capacity);
  region_block->capacity=capacity;
  region_block->type=t;
  region_block->next=NULL;
  A_ASSERT(region_block!=NULL);
  return region_block;
  
}

void append_data(Region *block, Types t, void *data,size_t count){
  
  (void)block;
  (void)t;
  (void)data;
  (void)count;
}

#endif // ARENA_IMP


