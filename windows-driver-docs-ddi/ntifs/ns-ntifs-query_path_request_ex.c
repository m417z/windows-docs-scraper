typedef struct _QUERY_PATH_REQUEST_EX {
  PIO_SECURITY_CONTEXT pSecurityContext;
  ULONG                EaLength;
  PVOID                pEaBuffer;
  UNICODE_STRING       PathName;
  UNICODE_STRING       DomainServiceName;
  PECP_LIST            EcpList;
  PESILO               Silo;
#if ...
  ULONG_PTR            Reserved;
#else
  ULONG_PTR            Reserved[2];
#endif
} QUERY_PATH_REQUEST_EX, *PQUERY_PATH_REQUEST_EX;