#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "_file_system_.h"


#ifndef _INIT_H
  #define _INIT_H 01
  
  #define _USAGE_         "Usage: [-u username] [-p password]\n"
  #define _MISSING_U      "Missing: [-u password]\n"
  #define _MISSING_P      "Missing: [-p username]\n"
  #define _SHADOW_FORMAT  "%c:%s:%s\n"
  
  /// @brief 
  void            _help();

  /// @brief 
  /// @param      argc 
  /// @param      args 
  void            _login(_i32 argc, char **args);

  /// @brief 
  /// @param      _p 
  /// @param      _u 
  void            _check_p_u(_ui8 *_p, _ui8 *_u);

  /// @brief 
  /// @param      _u 
  void            login_success(_ui8 *_u);

  /// @brief  
  void            login_fail();

  /// @brief 
  /// @param      arr 
  /// @return 
  extern  _ui32   _str_len(char *arr);

/// @brief 
/// @param str 
/// @return 
  extern _ui32    _const_str_len(const char *str);

  /// @brief 
  /// @param      arr1 
  /// @param      str 
  /// @return 
  extern  _ui8    _str_comp(char *arr1, const char *str);

  /// @brief 
  /// @param      arr1 
  /// @param      str 
  /// @return 
  extern  _ui8    _str_copy(char *arr1, _ui32 size_arr, const char *str);

  /// @brief 
  /// @param      arr
  /// @param      size_arr
  /// @param      str 
  /// @return 
  extern  _ui8    _str_cat(char *arr, _ui32 size_arr, const char *str);

  /// @brief 
  /// @param line 
  /// @param u_name 
  /// @param pass 
  /// @return 
  extern _ui8     _parse_line_put_u_p(_ui8 line[MAX_LINE_LENGTH], _ui8 u_name[SIZE_U_NAME], _ui8 pass[SIZE_PASS]);
  
  /// @brief 
  /// @param      string 
  /// @param      outputBuffer 
  extern  void    sha256_hash_string(const char *string, unsigned char outputBuffer[65]);


#endif