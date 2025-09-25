typedef struct _QUERY_SERVICE_CONFIGW {
  DWORD  dwServiceType;
  DWORD  dwStartType;
  DWORD  dwErrorControl;
  LPWSTR lpBinaryPathName;
  LPWSTR lpLoadOrderGroup;
  DWORD  dwTagId;
  LPWSTR lpDependencies;
  LPWSTR lpServiceStartName;
  LPWSTR lpDisplayName;
} QUERY_SERVICE_CONFIGW, *LPQUERY_SERVICE_CONFIGW;