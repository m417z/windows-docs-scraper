typedef struct _PPP_ATCP_INFO {
  DWORD dwError;
  WCHAR wszAddress[ATADDRESSLEN + 1];
} PPP_ATCP_INFO;