typedef struct _WLX_CLIENT_CREDENTIALS_INFO_2_0 {
  DWORD dwType;
  PWSTR pszUserName;
  PWSTR pszDomain;
  PWSTR pszPassword;
  BOOL  fPromptForPassword;
  BOOL  fDisconnectOnLogonFailure;
} WLX_CLIENT_CREDENTIALS_INFO_V2_0, *PWLX_CLIENT_CREDENTIALS_INFO_V2_0;