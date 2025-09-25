HRESULT DSCreateISecurityInfoObjectEx(
  [in]           LPCWSTR                pwszObjectPath,
  [in]           LPCWSTR                pwszObjectClass,
  [in]           LPCWSTR                pwszServer,
  [in]           LPCWSTR                pwszUserName,
  [in]           LPCWSTR                pwszPassword,
  [in]           DWORD                  dwFlags,
  [out]          LPSECURITYINFO         *ppSI,
  [in, optional] PFNREADOBJECTSECURITY  pfnReadSD,
  [in, optional] PFNWRITEOBJECTSECURITY pfnWriteSD,
  [in]           LPARAM                 lpContext
);