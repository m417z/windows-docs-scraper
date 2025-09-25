typedef struct _WINHTTP_PROXY_RESULT_ENTRY {
  BOOL            fProxy;
  BOOL            fBypass;
  INTERNET_SCHEME ProxyScheme;
  PWSTR           pwszProxy;
  INTERNET_PORT   ProxyPort;
} WINHTTP_PROXY_RESULT_ENTRY;