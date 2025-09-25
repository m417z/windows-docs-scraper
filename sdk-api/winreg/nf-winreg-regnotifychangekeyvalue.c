LSTATUS RegNotifyChangeKeyValue(
  [in]           HKEY   hKey,
  [in]           BOOL   bWatchSubtree,
  [in]           DWORD  dwNotifyFilter,
  [in, optional] HANDLE hEvent,
  [in]           BOOL   fAsynchronous
);