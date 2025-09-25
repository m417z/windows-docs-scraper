typedef struct _PPP_IPCP_INFO {
  DWORD dwError;
  WCHAR wszAddress[IPADDRESSLEN + 1];
  WCHAR wszRemoteAddress[IPADDRESSLEN + 1];
} PPP_IPCP_INFO;