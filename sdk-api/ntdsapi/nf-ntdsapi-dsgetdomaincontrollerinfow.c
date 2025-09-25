NTDSAPI DWORD DsGetDomainControllerInfoW(
  [in]  HANDLE  hDs,
  [in]  LPCWSTR DomainName,
  [in]  DWORD   InfoLevel,
  [out] DWORD   *pcOut,
  [out] VOID    **ppInfo
);