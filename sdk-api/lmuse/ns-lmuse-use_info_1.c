typedef struct _USE_INFO_1 {
  LMSTR ui1_local;
  LMSTR ui1_remote;
  LMSTR ui1_password;
  DWORD ui1_status;
  DWORD ui1_asg_type;
  DWORD ui1_refcount;
  DWORD ui1_usecount;
} USE_INFO_1, *PUSE_INFO_1, *LPUSE_INFO_1;