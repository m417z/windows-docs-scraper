DSGETDCAPI DWORD DsGetDcNameW(
  [in]  LPCWSTR                  ComputerName,
  [in]  LPCWSTR                  DomainName,
  [in]  GUID                     *DomainGuid,
  [in]  LPCWSTR                  SiteName,
  [in]  ULONG                    Flags,
  [out] PDOMAIN_CONTROLLER_INFOW *DomainControllerInfo
);