typedef struct tagWINHTTP_CREDS {
  LPSTR lpszUserName;
  LPSTR lpszPassword;
  LPSTR lpszRealm;
  DWORD dwAuthScheme;
  LPSTR lpszHostName;
  DWORD dwPort;
} WINHTTP_CREDS, *PWINHTTP_CREDS;