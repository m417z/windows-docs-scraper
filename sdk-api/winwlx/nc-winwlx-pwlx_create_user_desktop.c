PWLX_CREATE_USER_DESKTOP PwlxCreateUserDesktop;

BOOL PwlxCreateUserDesktop(
  [in]  HANDLE hWlx,
  [in]  HANDLE hToken,
  [in]  DWORD Flags,
  [in]  PWSTR pszDesktopName,
  [out] PWLX_DESKTOP *ppDesktop
)
{...}