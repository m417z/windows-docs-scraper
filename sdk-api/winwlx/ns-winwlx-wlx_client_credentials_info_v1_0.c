typedef struct _WLX_CLIENT_CREDENTIALS_INFO {
  DWORD dwType;
  PWSTR pszUserName;
  PWSTR pszDomain;
  PWSTR pszPassword;
  BOOL  fPromptForPassword;
} WLX_CLIENT_CREDENTIALS_INFO_V1_0, *PWLX_CLIENT_CREDENTIALS_INFO_V1_0;