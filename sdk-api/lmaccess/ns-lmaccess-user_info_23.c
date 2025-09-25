typedef struct _USER_INFO_23 {
  LPWSTR usri23_name;
  LPWSTR usri23_full_name;
  LPWSTR usri23_comment;
  DWORD  usri23_flags;
  PSID   usri23_user_sid;
} USER_INFO_23, *PUSER_INFO_23, *LPUSER_INFO_23;