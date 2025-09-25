typedef struct _MONITORUI {
  DWORD dwMonitorUISize;
  BOOL()(PCWSTR pszServer,HWND hWnd,PCWSTR pszMonitorNameIn,PWSTR *ppszPortNameOut) * pfnAddPortUI;
  BOOL( )(PCWSTR pName,HWND hWnd,PCWSTR pPortName) *pfnConfigurePortUI;
  BOOL( )(PCWSTR pszServer,HWND hWnd,PCWSTR pszPortName) *pfnDeletePortUI;
} MONITORUI, *PMONITORUI;