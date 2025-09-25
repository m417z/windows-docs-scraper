DSGETDCAPI DWORD DsDeregisterDnsHostRecordsA(
  [in, optional] LPSTR ServerName,
  [in, optional] LPSTR DnsDomainName,
  [in, optional] GUID  *DomainGuid,
  [in, optional] GUID  *DsaGuid,
  [in]           LPSTR DnsHostName
);