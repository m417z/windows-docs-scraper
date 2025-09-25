typedef struct _DNS_QUERY_REQUEST3 {
  ULONG                         Version;
  PCWSTR                        QueryName;
  WORD                          QueryType;
  ULONG64                       QueryOptions;
  PDNS_ADDR_ARRAY               pDnsServerList;
  ULONG                         InterfaceIndex;
  PDNS_QUERY_COMPLETION_ROUTINE pQueryCompletionCallback;
  PVOID                         pQueryContext;
  BOOL                          IsNetworkQueryRequired;
  DWORD                         RequiredNetworkIndex;
  DWORD                         cCustomServers;
  DNS_CUSTOM_SERVER             *pCustomServers;
} DNS_QUERY_REQUEST3, *PDNS_QUERY_REQUEST3;