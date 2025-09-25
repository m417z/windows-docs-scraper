typedef struct _DNS_QUERY_REQUEST {
  ULONG                         Version;
  PCWSTR                        QueryName;
  WORD                          QueryType;
  ULONG64                       QueryOptions;
  PDNS_ADDR_ARRAY               pDnsServerList;
  ULONG                         InterfaceIndex;
  PDNS_QUERY_COMPLETION_ROUTINE pQueryCompletionCallback;
  PVOID                         pQueryContext;
} DNS_QUERY_REQUEST, *PDNS_QUERY_REQUEST;