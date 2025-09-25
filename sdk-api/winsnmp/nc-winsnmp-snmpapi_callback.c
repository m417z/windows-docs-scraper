SNMPAPI_CALLBACK SnmpapiCallback;

SNMPAPI_STATUS SnmpapiCallback(
  [in] HSNMP_SESSION hSession,
  [in] HWND hWnd,
  [in] UINT wMsg,
  [in] WPARAM wParam,
  [in] LPARAM lParam,
  [in] LPVOID lpClientData
)
{...}