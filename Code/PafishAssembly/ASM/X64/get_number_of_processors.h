#ifndef _GET_NUMBER_OF_PROCESSORS_H_
#define _GET_NUMBER_OF_PROCESSORS_H_  

#if defined(__cplusplus)
extern "C" size_t __stdcall get_number_of_processors();
#else
extern size_t __stdcall get_number_of_processors();
#endif

#endif