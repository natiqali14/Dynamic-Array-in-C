#include <stdint.h>
#define DEFAULT_CAPACITY 1
#define RESIZE_MULTIPLIER 2

void* _create_darray(uint64_t type_size,int capacity);
void  _push_back(void** array, void* element);
void _pop(void* array, void* dst);
void _resize_darray(void** array);
void _get_at(void* array, uint64_t index, void* dst);
void _set_at(void* array, uint64_t index, void* element);
uint64_t _get_size(void* array);
void _erase_at(void* array,uint64_t index);
void _destroy(void** array);



#define create_darray(type)                               \
    _create_darray(sizeof(type),DEFAULT_CAPACITY)

#define darray_push_back(array,element)                   \
{                                                         \
    typeof(element) temp = element;                       \
    _push_back(&array,&temp);                             \
}

#define darray_pop(array,dst)                             \
    _pop(array,dst)

#define darray_get_at(array,index,dst)                    \
    _get_at(array,index,dst)


#define darray_set_at(array,index,element)                \
{                                                         \
    typeof(element) temp = element;                       \
    _set_at(array,index,&temp);                           \
}

#define darray_get_size(array) _get_size(array)
#define darray_erase_at(array,index) _erase_at(array,index)
#define darray_destroy(array) _destroy(&array)

