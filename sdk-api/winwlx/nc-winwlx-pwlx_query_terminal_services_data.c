PWLX_QUERY_TERMINAL_SERVICES_DATA PwlxQueryTerminalServicesData;

DWORD PwlxQueryTerminalServicesData(
  [in]  HANDLE hWlx,
  [out] PWLX_TERMINAL_SERVICES_DATA pTSData,
  [in]  WCHAR *UserName,
  [in]  WCHAR *Domain
)
{...}