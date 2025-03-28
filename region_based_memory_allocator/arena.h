#ifndef ARENA_H
#define ARENA_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<assert.h>

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

Arena* allocate_arena();
Region* allocate_region(size_t capacity,Types t);


#endif// ARENA_H

#ifdef ARENA_IMP

// alloated area
Arena* allocate_arena(){
  Arena*alloc_space=malloc(sizeof(Arena));
  A_ASSERT(alloc_space!=NULL);
  alloc_space->begin=NULL;
  alloc_space->end=NULL;
  alloc_space->region_count=0;
  alloc_space->region_capacity=ARENA_REGION_CAPACITY;
  return alloc_space;
}

Region* allocate_region(size_t capacity,Types t){
  
  Region*region_block=malloc(sizeof(Region));
  A_ASSERT(region!=NULL);

 switch(t){
    
   case CHAR:
    {
      region_block->mem_region=malloc(sizeof(char)*capacity);
      region_block->capacity=capacity;
      region_block->type=t;
      region_block->next=NULL;
    }
    break;
    
  case INT:
    {
      region_block->mem_region=malloc(sizeof(int)*capacity);
      region_block->capacity=capacity;
      region_block->type=t;
      region_block->next=NULL;
    }
    break;
    
      case FLOAT:
    {
      region_block->mem_region=malloc(sizeof(float)*capacity);
      region_block->capacity=capacity;
      region_block->type=t;
      region_block->next=NULL;
    }
    break;
    
  case DOUBLE:
    {
      region_block->mem_region=malloc(sizeof(double)*capacity);
      region_block->capacity=capacity;
      region_block->type=t;
      region_block->next=NULL;
    }
    break;

  case UINT:
    {
      region_block->mem_region=malloc(sizeof(unsigned int)*capacity);
      region_block->capacity=capacity;
      region_block->type=t;
      region_block->next=NULL;
  }break;
    
  default:
    
  }
 A_ASSERT(region_block!=NULL);
 return region_block;
}


#endif // ARENA_IMP

