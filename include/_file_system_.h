#include "_types_.h"




#ifndef _FILE_SYSTEM_H
  #define _FILE_SYSTEM_H    0x1
  /// @brief exception levels:
  ///@param el0 owner read write / admin read write
  ///@param el1 owner read / admin read write
  ///@param el2 admin read write 
  typedef enum _E_level{
    el0 = 00,
    el1 = 01,
    el2 = 02
  }_E_level;

  /// @brief file struct
  typedef struct _File{
    char f_name[SIZE_BUFF_NAME];
    _ui32 size; // in bytes
    char owner[SIZE_U_NAME];
    _E_level e_level;
  }_File;
  
  /// @brief directory struct
  typedef struct _Dir{
    char d_name[SIZE_BUFF_NAME];
    char owner[SIZE_U_NAME]; 
    _E_level e_level;
  }_Dir;

  /// @brief types of tree node
  typedef union _Node_type{
    _Dir dir;
    _File file;
  }_Node_type;

  /// @brief tree node
  typedef struct _File_sys_tree_node{
    _Node_type type;
    struct _File_sys_tree_node *next;
  }_File_sys_tree_node;
  
  _File_sys_tree_node __ROOT = {
    .type.dir.d_name = "root",
    .type.dir.e_level = el2,
    .type.dir.owner = "admin"
  };

#endif

// add tree functions



//####################################################

#ifndef _USERS_
  #define _USERS_       0x1
  #define SIZE_F_NAME   0x1E
  #define SIZE_L_NAME   0x1E
  
  /// @brief permission levels:
  ///@param Pl0 users 
  ///@param Pl1 admin
  typedef enum _P_level{
    pl0 = 00,
    pl1 = 01,
  }_P_level;
  
  /// @brief 2 lvls: users and admin (No sudo)
  typedef struct User{
    _ui8 id;
    char first_name[SIZE_F_NAME];
    char last_name[SIZE_L_NAME];
    _Dir *home_folder;
  }User;
  
#endif