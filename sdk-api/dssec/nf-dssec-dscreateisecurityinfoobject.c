HRESULT DSCreateISecurityInfoObject(
  [in]           LPCWSTR                pwszObjectPath,
  [in]           LPCWSTR                pwszObjectClass,
  [in]           DWORD                  dwFlags,
  [out]          LPSECURITYINFO         *ppSI,
  [in, optional] PFNREADOBJECTSECURITY  pfnReadSD,
  [in, optional] PFNWRITEOBJECTSECURITY pfnWriteSD,
  [in]           LPARAM                 lpContext
);