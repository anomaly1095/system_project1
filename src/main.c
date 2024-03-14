#include "../include/_init_.h"

int main(int argc, char **argv){
  // min number of args
  if (argc < 5){
    printf(_USAGE_);
    exit(NO_ARGS);
  }

  _login(argc, argv);
  // _shell();
  return 0x0;
}


void _help(){

}


void _login(_i32 argc, char **argv){
  _ui8 res_p = 00, res_u = 00, *_u, *_p;

  for (_ui8 i = 01; i < argc; ++i){
    if (_str_comp(argv[i], "-u") == _SUCCESS && (i+1) < (_ui8)argc){
      _u = argv[i+1];
      res_u++;
    }
    else if (_str_comp(argv[i], "-p") == _SUCCESS && (i+1) < (_ui8)argc){
      _p = argv[i+1];
      res_p++;
    }
  }
  if (!res_u){
    system("clear");
    printf(_USAGE_);
    exit(U_MISSING);
  }
  if (!res_p){
    system("clear");
    printf(_USAGE_);
    exit(P_MISSING);
  }
  _check_p_u(_p, _u);
}


void _check_p_u(_ui8 *_p, _ui8 *_u) {
  FILE *shadow = fopen(SHADOW_PATH, "r");
  if (shadow == NULL)
    exit(F_NOT_FOUND);

  char line[MAX_LINE_LENGTH];  // Buffer to store each line
  while (fgets(line, sizeof(line), shadow) != NULL) {
    _ui8 u_name[SIZE_U_NAME];
    _ui8 pass[SIZE_PASS];

    
    if (_parse_line_put_u_p(line, u_name, pass) == _SUCCESS) {
      
      if (_str_comp(_u, u_name) == _SUCCESS) {
        _ui8 enteredHashedPassword[SIZE_HASH];
        sha256_hash_string(_p, enteredHashedPassword);

        if (_str_comp(enteredHashedPassword, pass) == _SUCCESS) {
          login_success(_u);
          fclose(shadow);
          return;
        }
      }
    }else {exit(CRED_PARSE_ERROR);}
  }
  fclose(shadow);
  login_fail();
}


void login_success(_ui8 *_u){
  FILE *_syslogs = fopen(SYSLOG_PATH, "a");
  if (_syslogs == NULL)
    exit(F_NOT_FOUND);
  time_t currentTime;
  time(&currentTime);
  fprintf(_syslogs, "User: %s logged at %s.\n", _u, ctime(&currentTime));
  fclose(_syslogs);
}


void login_fail(){
  FILE *_syslogs = fopen(SYSLOG_PATH, "a");
  if (_syslogs == NULL)
    exit(F_NOT_FOUND);
  time_t currentTime;
  time(&currentTime);
  fprintf(_syslogs, "Login attempt failed at: %s.\n", ctime(&currentTime));
  fclose(_syslogs);
  exit(WRONG_CRED);
}