typedef struct _USER_INFO_20 {
  LPWSTR usri20_name;
  LPWSTR usri20_full_name;
  LPWSTR usri20_comment;
  DWORD  usri20_flags;
  DWORD  usri20_user_id;
} USER_INFO_20, *PUSER_INFO_20, *LPUSER_INFO_20;