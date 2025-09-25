typedef struct _USE_INFO_2 {
  LMSTR ui2_local;
  LMSTR ui2_remote;
  LMSTR ui2_password;
  DWORD ui2_status;
  DWORD ui2_asg_type;
  DWORD ui2_refcount;
  DWORD ui2_usecount;
  LMSTR ui2_username;
  LMSTR ui2_domainname;
} USE_INFO_2, *PUSE_INFO_2, *LPUSE_INFO_2;