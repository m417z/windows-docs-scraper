NTDSAPI DWORD DsRemoveDsServerA(
  [in]            HANDLE hDs,
  [in]            LPSTR  ServerDN,
  [in, optional]  LPSTR  DomainDN,
  [out, optional] BOOL   *fLastDcInDomain,
  [in]            BOOL   fCommit
);