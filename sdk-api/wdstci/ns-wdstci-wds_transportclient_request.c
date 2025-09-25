typedef struct _WDS_TRANSPORTCLIENT_REQUEST {
  ULONG   ulLength;
  ULONG   ulApiVersion;
  ULONG   ulAuthLevel;
  LPCWSTR pwszServer;
  LPCWSTR pwszNamespace;
  LPCWSTR pwszObjectName;
  ULONG   ulCacheSize;
  ULONG   ulProtocol;
  PVOID   pvProtocolData;
  ULONG   ulProtocolDataLength;
} WDS_TRANSPORTCLIENT_REQUEST, *PWDS_TRANSPORTCLIENT_REQUEST;