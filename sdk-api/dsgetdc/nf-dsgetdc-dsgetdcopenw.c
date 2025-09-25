DSGETDCAPI DWORD DsGetDcOpenW(
  [in]           LPCWSTR DnsName,
  [in]           ULONG   OptionFlags,
  [in, optional] LPCWSTR SiteName,
  [in, optional] GUID    *DomainGuid,
  [in, optional] LPCWSTR DnsForestName,
  [in]           ULONG   DcFlags,
  [out]          PHANDLE RetGetDcContext
);