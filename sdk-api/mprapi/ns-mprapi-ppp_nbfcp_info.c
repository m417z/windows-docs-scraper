typedef struct _PPP_NBFCP_INFO {
  DWORD dwError;
  WCHAR wszWksta[NETBIOS_NAME_LEN + 1];
} PPP_NBFCP_INFO;