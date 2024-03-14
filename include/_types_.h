//####################################################

#ifndef   _ERRORS_
  #define _ERRORS_          0x1
  #define _SUCCESS          0x0
  #define _FAILURE          0x1
  #define NO_ARGS           0x2
  #define U_MISSING         0x3
  #define P_MISSING         0x4
  #define F_NOT_FOUND       0x5
  #define WRONG_CRED        0x6
  #define HASH_FAIL         0x7
  #define CRED_PARSE_ERROR  0X8
  #define U_NAME_OVERFLOW   0x9
  #define PASS_OVERFLOW     0xA
  #define ARCH_ERROR        0x32

#endif
#ifndef   _STRINGS_
  #define _STRINGS_         0x1
  #define SIZE_HASH         0x41
  #define SIZE_ID           0x3
  #define SIZE_U_NAME       0x1E
  #define SIZE_PASS         0x3C
  #define SIZE_BUFF_NAME    0X1E
  #define MAX_LINE_LENGTH   0x5D
  #define CHAR_TO_INT       0b110000
  #define SHADOW_PATH       "root/admin/shadow"
  #define SYSLOG_PATH       "root/admin/syslogs.log"
#endif
//####################################################

#ifndef _TYPES_
  #define _TYPES_ 1
  #if defined(__x86_64__) || defined(__arm__)
    #define _ui8            unsigned char
    #define _i8             signed char
    #define _ui16           unsigned short
    #define _i16            signed short
    #define _ui32           unsigned int
    #define _i32            signed int 
    #define _l64            signed long
    #define _ul64           unsigned long
    #define _ll64           signed long long
    #define _ull64          unsigned long long    
  #else
    #error  ARCH_ERROR //32 bit arch not supported
  #endif

#endif // _TYPES_ 1

//####################################################