long BroadcastSystemMessageExW(
  [in]                DWORD    flags,
  [in, out, optional] LPDWORD  lpInfo,
  [in]                UINT     Msg,
  [in]                WPARAM   wParam,
  [in]                LPARAM   lParam,
  [out, optional]     PBSMINFO pbsmInfo
);