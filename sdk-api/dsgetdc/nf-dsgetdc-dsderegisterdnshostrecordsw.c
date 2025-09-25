DSGETDCAPI DWORD DsDeregisterDnsHostRecordsW(
  [in, optional] LPWSTR ServerName,
  [in, optional] LPWSTR DnsDomainName,
  [in, optional] GUID   *DomainGuid,
  [in, optional] GUID   *DsaGuid,
  [in]           LPWSTR DnsHostName
);