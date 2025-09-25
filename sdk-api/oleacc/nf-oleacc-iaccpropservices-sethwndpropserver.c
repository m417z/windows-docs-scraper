HRESULT SetHwndPropServer(
  [in] HWND             hwnd,
  [in] DWORD            idObject,
  [in] DWORD            idChild,
  [in] const MSAAPROPID *paProps,
  [in] int              cProps,
  [in] IAccPropServer   *pServer,
  [in] AnnoScope        annoScope
);