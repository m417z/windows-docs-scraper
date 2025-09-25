typedef struct _DNS_QUERY_RESULT {
  ULONG       Version;
  DNS_STATUS  QueryStatus;
  ULONG64     QueryOptions;
  PDNS_RECORD pQueryRecords;
  PVOID       Reserved;
} DNS_QUERY_RESULT, *PDNS_QUERY_RESULT;