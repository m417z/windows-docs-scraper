typedef struct _DNS_SERVICE_BROWSE_REQUEST {
  ULONG  Version;
  ULONG  InterfaceIndex;
  PCWSTR QueryName;
  union {
    PDNS_SERVICE_BROWSE_CALLBACK pBrowseCallback;
    DNS_QUERY_COMPLETION_ROUTINE *pBrowseCallbackV2;
  };
  PVOID  pQueryContext;
} DNS_SERVICE_BROWSE_REQUEST, *PDNS_SERVICE_BROWSE_REQUEST;