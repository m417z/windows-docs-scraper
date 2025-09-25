DSGETDCAPI DWORD DsEnumerateDomainTrustsA(
  [in, optional] LPSTR              ServerName,
  [in]           ULONG              Flags,
  [out]          PDS_DOMAIN_TRUSTSA *Domains,
  [out]          PULONG             DomainCount
);