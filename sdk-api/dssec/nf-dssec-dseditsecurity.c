HRESULT DSEditSecurity(
  [in]           HWND                   hwndOwner,
  [in]           LPCWSTR                pwszObjectPath,
  [in, optional] LPCWSTR                pwszObjectClass,
  [in]           DWORD                  dwFlags,
  [in, optional] LPCWSTR                pwszCaption,
  [in, optional] PFNREADOBJECTSECURITY  pfnReadSD,
  [in, optional] PFNWRITEOBJECTSECURITY pfnWriteSD,
  [in]           LPARAM                 lpContext
);