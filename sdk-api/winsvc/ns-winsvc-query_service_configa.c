typedef struct _QUERY_SERVICE_CONFIGA {
  DWORD dwServiceType;
  DWORD dwStartType;
  DWORD dwErrorControl;
  LPSTR lpBinaryPathName;
  LPSTR lpLoadOrderGroup;
  DWORD dwTagId;
  LPSTR lpDependencies;
  LPSTR lpServiceStartName;
  LPSTR lpDisplayName;
} QUERY_SERVICE_CONFIGA, *LPQUERY_SERVICE_CONFIGA;