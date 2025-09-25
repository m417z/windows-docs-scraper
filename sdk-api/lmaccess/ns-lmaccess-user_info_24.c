typedef struct _USER_INFO_24 {
  BOOL   usri24_internet_identity;
  DWORD  usri24_flags;
  LPWSTR usri24_internet_provider_name;
  LPWSTR usri24_internet_principal_name;
  PSID   usri24_user_sid;
} USER_INFO_24, *PUSER_INFO_24, *LPUSER_INFO_24;