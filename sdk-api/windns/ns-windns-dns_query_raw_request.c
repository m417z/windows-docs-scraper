typedef struct _DNS_QUERY_RAW_REQUEST {
  ULONG                            version;
  ULONG                            resultsVersion;
  ULONG                            dnsQueryRawSize;
  BYTE                             *dnsQueryRaw;
  PWSTR                            dnsQueryName;
  USHORT                           dnsQueryType;
  ULONG64                          queryOptions;
  ULONG                            interfaceIndex;
  DNS_QUERY_RAW_COMPLETION_ROUTINE queryCompletionCallback;
  VOID                             *queryContext;
  ULONG64                          queryRawOptions;
  ULONG                            customServersSize;
  DNS_CUSTOM_SERVER                *customServers;
  ULONG                            protocol;
  union {
    SOCKADDR_INET sourceAddr;
    CHAR          maxSa[DNS_ADDR_MAX_SOCKADDR_LENGTH];
  };
} DNS_QUERY_RAW_REQUEST;