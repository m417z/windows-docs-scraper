NTDSAPI DWORD DsGetDomainControllerInfoA(
  [in]  HANDLE hDs,
  [in]  LPCSTR DomainName,
  [in]  DWORD  InfoLevel,
  [out] DWORD  *pcOut,
  [out] VOID   **ppInfo
);