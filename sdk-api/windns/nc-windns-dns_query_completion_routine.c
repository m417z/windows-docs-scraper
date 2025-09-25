DNS_QUERY_COMPLETION_ROUTINE DnsQueryCompletionRoutine;

VOID DnsQueryCompletionRoutine(
  [in]      PVOID pQueryContext,
  [in, out] PDNS_QUERY_RESULT pQueryResults
)
{...}