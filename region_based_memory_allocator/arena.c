#include<stdio.h>

#define ARENA_SIZE 100 // node of list

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

Region *begin=NULL;
Region *end=NULL;
void allocate_region(size_t size, size_t capacity,Types t){

}

int main(){
  
  return 0;
}
