NTDSAPI DWORD DsRemoveDsServerW(
  [in]            HANDLE hDs,
  [in]            LPWSTR ServerDN,
  [in, optional]  LPWSTR DomainDN,
  [out, optional] BOOL   *fLastDcInDomain,
  [in]            BOOL   fCommit
);