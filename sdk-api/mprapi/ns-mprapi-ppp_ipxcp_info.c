typedef struct _PPP_IPXCP_INFO {
  DWORD dwError;
  WCHAR wszAddress[IPXADDRESSLEN + 1];
} PPP_IPXCP_INFO;