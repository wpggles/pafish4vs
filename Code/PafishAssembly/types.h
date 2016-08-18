
#ifndef TYPES_H
#define TYPES_H

//disable 4996 warning for using unsafe function
#pragma warning(disable:4996)

#define TRUE  1
#define FALSE 0

typedef char * string;

#ifndef snprintf
#define snprintf _snprintf
#endif

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

#endif
