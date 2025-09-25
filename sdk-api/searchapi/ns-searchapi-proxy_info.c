typedef struct _PROXY_INFO {
  DWORD        dwSize;
  LPCWSTR      pcwszUserAgent;
  PROXY_ACCESS paUseProxy;
  BOOL         fLocalBypass;
  DWORD        dwPortNumber;
  LPCWSTR      pcwszProxyName;
  LPCWSTR      pcwszBypassList;
} PROXY_INFO;