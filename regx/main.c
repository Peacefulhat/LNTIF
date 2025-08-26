#define REGX_IMPLEMENTATION
#include "regx.h"


int main(int argc, char** argv)
{
    FSM s = {0};
    alloc_buffer(&s,MAX_STATE_COUNT);
    fill_range(s.buffer+8,5,66);
    print_state(s);
    free(s.buffer);
    return 0;
}

