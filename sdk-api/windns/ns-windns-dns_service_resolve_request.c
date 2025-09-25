typedef struct _DNS_SERVICE_RESOLVE_REQUEST {
  ULONG                         Version;
  ULONG                         InterfaceIndex;
  PWSTR                         QueryName;
  PDNS_SERVICE_RESOLVE_COMPLETE pResolveCompletionCallback;
  PVOID                         pQueryContext;
} DNS_SERVICE_RESOLVE_REQUEST, *PDNS_SERVICE_RESOLVE_REQUEST;