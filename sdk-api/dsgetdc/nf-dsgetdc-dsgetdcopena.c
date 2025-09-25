DSGETDCAPI DWORD DsGetDcOpenA(
  [in]           LPCSTR  DnsName,
  [in]           ULONG   OptionFlags,
  [in, optional] LPCSTR  SiteName,
  [in, optional] GUID    *DomainGuid,
  [in, optional] LPCSTR  DnsForestName,
  [in]           ULONG   DcFlags,
  [out]          PHANDLE RetGetDcContext
);