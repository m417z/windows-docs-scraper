HRESULT RIL_Initialize(
  DWORD             dwIndex,
  RILRESULTCALLBACK pfnResult,
  RILNOTIFYCALLBACK pfnNotify,
  DWORD             *lpdwNotifications,
  DWORD             dwNotificationCount,
  LPVOID            lpParam,
  WCHAR             *pwszClientName,
  HRIL              *lphRil
);