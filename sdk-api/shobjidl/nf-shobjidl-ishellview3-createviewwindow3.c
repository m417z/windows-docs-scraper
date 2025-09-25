HRESULT CreateViewWindow3(
  [in]  IShellBrowser     *psbOwner,
  [in]  IShellView        *psvPrev,
  [in]  SV3CVW3_FLAGS     dwViewFlags,
  [in]  FOLDERFLAGS       dwMask,
  [in]  FOLDERFLAGS       dwFlags,
  [in]  FOLDERVIEWMODE    fvMode,
  [in]  const SHELLVIEWID *pvid,
  [in]  const RECT        *prcView,
  [out] HWND              *phwndView
);