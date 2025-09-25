DNS_SERVICE_BROWSE_CALLBACK DnsServiceBrowseCallback;

VOID DnsServiceBrowseCallback(
  DWORD Status,
  PVOID pQueryContext,
  PDNS_RECORD pDnsRecord
)
{...}