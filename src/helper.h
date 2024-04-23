#include <stdio.h>
#define ASSERT(expression,msg)                                       \
{                                                                \
    if(expression) {                                            \
    }                                                            \
    else{ \
        printf("%s\n%s in %s at %d\n",msg,#expression,__FILE__,__LINE__);  \
        __builtin_trap();\
    }\
}