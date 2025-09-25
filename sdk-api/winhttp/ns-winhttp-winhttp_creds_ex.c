typedef struct tagWINHTTP_CREDS_EX {
  LPSTR lpszUserName;
  LPSTR lpszPassword;
  LPSTR lpszRealm;
  DWORD dwAuthScheme;
  LPSTR lpszHostName;
  DWORD dwPort;
  LPSTR lpszUrl;
} WINHTTP_CREDS_EX, *PWINHTTP_CREDS_EX;