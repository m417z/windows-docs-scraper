DNS_SERVICE_RESOLVE_COMPLETE DnsServiceResolveComplete;

VOID DnsServiceResolveComplete(
  DWORD Status,
  PVOID pQueryContext,
  PDNS_SERVICE_INSTANCE pInstance
)
{...}