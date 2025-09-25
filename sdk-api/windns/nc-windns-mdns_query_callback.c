MDNS_QUERY_CALLBACK MdnsQueryCallback;

VOID MdnsQueryCallback(
  PVOID pQueryContext,
  PMDNS_QUERY_HANDLE pQueryHandle,
  PDNS_QUERY_RESULT pQueryResults
)
{...}