HRESULT DSCreateSecurityPage(
  [in]           LPCWSTR                pwszObjectPath,
  [in, optional] LPCWSTR                pwszObjectClass,
  [in]           DWORD                  dwFlags,
  [out]          HPROPSHEETPAGE         *phPage,
  [in, optional] PFNREADOBJECTSECURITY  pfnReadSD,
  [in, optional] PFNWRITEOBJECTSECURITY pfnWriteSD,
  [in]           LPARAM                 lpContext
);