typedef struct _PROFILEINFOW {
  DWORD              dwSize;
  DWORD              dwFlags;
  MIDL_STRING LPWSTR lpUserName;
  MIDL_STRING LPWSTR lpProfilePath;
  MIDL_STRING LPWSTR lpDefaultPath;
  MIDL_STRING LPWSTR lpServerName;
  MIDL_STRING LPWSTR lpPolicyPath;
#if ...
  ULONG_PTR          hProfile;
#else
  HANDLE             hProfile;
#endif
} PROFILEINFOW, *LPPROFILEINFOW;