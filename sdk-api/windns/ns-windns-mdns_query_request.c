typedef struct _MDNS_QUERY_REQUEST {
  ULONG                Version;
  ULONG                ulRefCount;
  PCWSTR               Query;
  WORD                 QueryType;
  ULONG64              QueryOptions;
  ULONG                InterfaceIndex;
  PMDNS_QUERY_CALLBACK pQueryCallback;
  PVOID                pQueryContext;
  BOOL                 fAnswerReceived;
  ULONG                ulResendCount;
} MDNS_QUERY_REQUEST, *PMDNS_QUERY_REQUEST;