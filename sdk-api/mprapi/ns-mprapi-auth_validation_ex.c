typedef struct _AUTH_VALIDATION_EX {
  MPRAPI_OBJECT_HEADER Header;
  HANDLE               hRasConnection;
  WCHAR                wszUserName[UNLEN + 1];
  WCHAR                wszLogonDomain[DNLEN + 1];
  DWORD                AuthInfoSize;
  BYTE                 AuthInfo[1];
} AUTH_VALIDATION_EX;