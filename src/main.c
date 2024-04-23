#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "darry.h"
typedef struct test_struct {
    uint64_t number;

} test_struct;
int main() {
    void* array  = create_darray(int);
    darray_push_back(array,1);
    darray_push_back(array,12);
    darray_push_back(array,13);
    darray_push_back(array,14);
    darray_push_back(array,15);
    darray_push_back(array,16);
    darray_push_back(array,17);
    darray_push_back(array,18);
    darray_push_back(array,19);
    darray_push_back(array,100);
    darray_push_back(array,199);
    darray_erase_at(array,3);
    darray_erase_at(array,4);
    int a;
    int b;
    darray_get_at(array,3,&a);
    darray_get_at(array,8,&b);
    printf("%d %d\n",a,b);
    return 0;
}