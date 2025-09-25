DSGETDCAPI DWORD DsEnumerateDomainTrustsW(
  [in, optional] LPWSTR             ServerName,
  [in]           ULONG              Flags,
  [out]          PDS_DOMAIN_TRUSTSW *Domains,
  [out]          PULONG             DomainCount
);