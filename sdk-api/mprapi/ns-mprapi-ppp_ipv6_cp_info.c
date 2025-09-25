typedef struct _PPP_IPV6_CP_INFO {
  DWORD dwVersion;
  DWORD dwSize;
  DWORD dwError;
  BYTE  bInterfaceIdentifier[8];
  BYTE  bRemoteInterfaceIdentifier[8];
  DWORD dwOptions;
  DWORD dwRemoteOptions;
  BYTE  bPrefix[8];
  DWORD dwPrefixLength;
} PPP_IPV6_CP_INFO;