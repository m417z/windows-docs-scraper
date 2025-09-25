typedef struct _PPP_IPCP_INFO2 {
  DWORD dwError;
  WCHAR wszAddress[IPADDRESSLEN + 1];
  WCHAR wszRemoteAddress[IPADDRESSLEN + 1];
  DWORD dwOptions;
  DWORD dwRemoteOptions;
} PPP_IPCP_INFO2;