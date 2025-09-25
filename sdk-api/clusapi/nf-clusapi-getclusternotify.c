DWORD GetClusterNotify(
  [in]           HCHANGE   hChange,
  [out]          DWORD_PTR *lpdwNotifyKey,
  [out]          LPDWORD   lpdwFilterType,
  [out]          LPWSTR    lpszName,
  [in, out]      LPDWORD   lpcchName,
  [in, optional] DWORD     dwMilliseconds
);