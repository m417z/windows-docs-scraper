typedef struct _PROFILEINFOA {
  DWORD             dwSize;
  DWORD             dwFlags;
  MIDL_STRING LPSTR lpUserName;
  MIDL_STRING LPSTR lpProfilePath;
  MIDL_STRING LPSTR lpDefaultPath;
  MIDL_STRING LPSTR lpServerName;
  MIDL_STRING LPSTR lpPolicyPath;
#if ...
  ULONG_PTR         hProfile;
#else
  HANDLE            hProfile;
#endif
} PROFILEINFOA, *LPPROFILEINFOA;