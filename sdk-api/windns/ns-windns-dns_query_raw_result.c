typedef struct _DNS_QUERY_RAW_RESULT {
  ULONG       version;
  DNS_STATUS  queryStatus;
  ULONG64     queryOptions;
  ULONG64     queryRawOptions;
  ULONG64     responseFlags;
  ULONG       queryRawResponseSize;
  BYTE        *queryRawResponse;
  PDNS_RECORD queryRecords;
  ULONG       protocol;
  union {
    SOCKADDR_INET sourceAddr;
    CHAR          maxSa[DNS_ADDR_MAX_SOCKADDR_LENGTH];
  };
} DNS_QUERY_RAW_RESULT;