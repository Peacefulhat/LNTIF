#ifndef ARENA_H
#define ARENA_H
#define ARENA_SIZE 100 // node of list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

typedef enum {
  CHAR,
  INTEGER,
  FLOAT,
  DOUBLE,
  UINT
}Types;

typedef struct{
  size_t count;
  size_t capacity;
  void*mem_region;
}Region;
  
typedef struct{
  Region*begin,*end;
  size_t region_count;
  size_t region_capacity;
  Region*region;
}Arena;

Arena block;

void allocate_region(size_t size, size_t capacity,Types t);

#endif// ARENA_H

#ifdef ARENA_IMP

void allocate_region(size_t size, size_t capacity,Types t){
if(block->begin
}


#endif // ARENA_IMP

