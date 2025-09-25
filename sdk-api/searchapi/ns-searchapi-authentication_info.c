typedef struct _AUTHENTICATION_INFO {
  DWORD     dwSize;
  AUTH_TYPE atAuthenticationType;
  LPCWSTR   pcwszUser;
  LPCWSTR   pcwszPassword;
} AUTHENTICATION_INFO;