#include "../include/_types_.h"
#include <openssl/evp.h>


_ui32 _str_len(char *arr){
_ui32 i;
  for (i = 00; arr[i] != 00; ++i){}
  return i;
}

_ui32 _const_str_len(const char *str){
_ui32 i;
  for (i = 00; str[i] != 00; ++i){}
  return i;
}

_ui8 _str_comp(char *arr1, const char *str){
_ui32 i;
  for (i = 00; i < _str_len(arr1) && i < _const_str_len(str); ++i){
    if (arr1[i] != str[i]) return _FAILURE;
  }
  return 0x0;
}

_ui8 _str_copy(char *arr, _ui32 size_arr, const char *str){
_ui32 i;
  for (i = 00; i < _const_str_len(str) && i < size_arr; ++i){
    arr[i] = str[i];
  }
  return _SUCCESS;
}

_ui8 _str_cat(char *arr, _ui32 size_arr, const char *str){
_ui32 i;
  for (i = 00; i < _str_len(arr) && i < size_arr; ++i){
    arr[i] = arr[i];
  }
  for (i = 00; i < _const_str_len(str) && i < size_arr; ++i){
    arr[i] = str[i];
  }
  return _SUCCESS;
}

_ui8 _parse_line_put_u_p(_ui8 line[MAX_LINE_LENGTH], _ui8 u_name[SIZE_U_NAME], _ui8 pass[SIZE_PASS]){
  _ui8 i = 00, x1 = 00, x2 = 00;
  
  for (i; line[i] != 00; ++i){
    if (line[i] == 0x3A) {x1 = i; break;} // x1 = index of first column
  }
  for (i++; line[i] != 00; ++i){
    if (line[i] == 0x3A) {x2 = i; break;}  // x2 = index of second column
  }
  
  if (x1 == 00 || x2 == 00) {exit(CRED_PARSE_ERROR);} // exit if column is missing
  
  i = 00;
  for (_ui8 j = x1+1; j < x2; ++j, ++i){ // copy username
    if (j > SIZE_U_NAME) {exit(U_NAME_OVERFLOW);}
    u_name[i] = line[j];
  }
  i = 00;
  for (_ui8 j = x2+1; line[j] != 00; ++j, ++i){ // copy password
    if (j > SIZE_PASS) {exit(PASS_OVERFLOW);}
    pass[i] = line[j];
  }
  return _SUCCESS;
}

void sha256_hash_string(const char *string, unsigned char outputBuffer[SIZE_HASH]) {
  EVP_MD_CTX *mdctx;
  const EVP_MD *sha256 = EVP_sha256();

  // Allocate EVP_MD_CTX
  if (!(mdctx = EVP_MD_CTX_create()))
    exit(HASH_FAIL);

  // Initialize EVP_MD_CTX with SHA256
  if (EVP_DigestInit_ex(mdctx, sha256, NULL) != 1)
    goto exit;
  
  // Update the context with the data
  if (EVP_DigestUpdate(mdctx, string, _const_str_len(string)) != 1)
    goto exit;
  
  // Finalize the hash computation
  if (EVP_DigestFinal_ex(mdctx, outputBuffer, NULL) != 1)
    goto exit;
  
  EVP_MD_CTX_destroy(mdctx);
  return;

  exit:
    EVP_MD_CTX_destroy(mdctx);
    exit(HASH_FAIL);
}
