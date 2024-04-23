#include "darry.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper.h"
typedef struct array_info {
    uint64_t capacity;
    uint64_t current_length;
    uint64_t stride;
} array_info;

void* _create_darray(uint64_t type_size, int capacity) {
    uint64_t total_size = sizeof(array_info) + (type_size * capacity);
    void* array = malloc(total_size);
    array_info* info = array;
    info->capacity = capacity;
    info->current_length = 0;
    info->stride = type_size;
    return (void*) info;
}
void  _push_back(void** array, void* element) {
    uint64_t header_size = sizeof(array_info);
    array_info* info = *array;
    if(info->current_length == info->capacity) {
        _resize_darray(array);
       
    }
    array_info* new_info = *array;
    uint64_t array_size;
    array_size = (new_info->current_length * new_info->stride);
    uint64_t address = (uint64_t) *array;
    memcpy((void*) (address + (array_size + header_size)),element,new_info->stride);
    new_info->current_length +=1;
}
void _pop(void* array, void* dst) {
    array_info* info = array;
    _get_at(array, info->current_length - 1, dst);
}

void _resize_darray(void** array) {
    array_info* info = *array;
    uint64_t prev_cap = info->capacity;
    uint64_t header_size = sizeof(array_info);
    uint64_t array_size = info->stride * info->current_length;
    uint64_t new_size = header_size + (info->stride * info->capacity * RESIZE_MULTIPLIER);
    void* temp = malloc(new_size);
    memcpy(temp, *array, array_size + header_size);
    free(*array);
    *array = temp;
    array_info* new_info = *array;
    new_info->capacity = prev_cap * RESIZE_MULTIPLIER;
}


void _get_at(void* array, uint64_t index, void* dst) {
    array_info* info = array;
    ASSERT(index <= (info->current_length -1) && info->current_length != 0,"ERROR INDEX OUT OF BOUND !!!!!");
    uint64_t header_size = sizeof(array_info);
    uint64_t address = (uint64_t)array;
    uint64_t target = address + header_size + (info->stride * index);
    memcpy(dst,(void*) target, info->stride);
}

void _set_at(void* array, uint64_t index, void* element) {
    array_info* info = array;
    ASSERT(index <= (info->current_length -1) && info->current_length != 0,"ERROR INDEX OUT OF BOUND !!!!!");
    uint64_t header_size = sizeof(array_info);
    uint64_t address = (uint64_t) array;
    uint64_t target = address + header_size + (info->stride * index);
    memcpy((void*)target,element,info->stride);
}
uint64_t _get_size(void* array) {
    array_info* info = array;
    return info->current_length;
}

void _erase_at(void* array,uint64_t index) {
    array_info* info = array;
    ASSERT(index <= (info->current_length -1) && info->current_length != 0,"ERROR INDEX OUT OF BOUND !!!!!");
    uint64_t address = (uint64_t) array;
    uint64_t target = address + (sizeof(array_info)) + (index * info->stride);
    uint64_t next_addr = address + (sizeof(array_info)) + ((index + 1) * info->stride);
    uint64_t total_size = info->current_length -index - 1;
    //memcpy();
    memmove((void*)target,(void*)next_addr,total_size * info->stride);
    info->current_length = info->current_length - 1;
}

void _destroy(void** array) {
    uint64_t address = (uint64_t) *array;
    free((void*) (address));
    *array = NULL;
}