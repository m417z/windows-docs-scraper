HRESULT Unpin(
  [in] HWND                      hwndParent,
  [in] LPCWSTR                   *rgpszPaths,
  [in] ULONG                     cPaths,
  [in] BOOL                      bDeep,
  [in] BOOL                      bAsync,
  [in] DWORD                     dwPinControlFlags,
  [in] IOfflineFilesSyncProgress *pIProgress
);