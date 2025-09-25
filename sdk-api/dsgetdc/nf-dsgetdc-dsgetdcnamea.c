DSGETDCAPI DWORD DsGetDcNameA(
  [in]  LPCSTR                   ComputerName,
  [in]  LPCSTR                   DomainName,
  [in]  GUID                     *DomainGuid,
  [in]  LPCSTR                   SiteName,
  [in]  ULONG                    Flags,
  [out] PDOMAIN_CONTROLLER_INFOA *DomainControllerInfo
);