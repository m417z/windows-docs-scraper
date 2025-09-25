typedef struct _FILE_INFO_3 {
  DWORD fi3_id;
  DWORD fi3_permissions;
  DWORD fi3_num_locks;
  LMSTR fi3_pathname;
  LMSTR fi3_username;
} FILE_INFO_3, *PFILE_INFO_3, *LPFILE_INFO_3;