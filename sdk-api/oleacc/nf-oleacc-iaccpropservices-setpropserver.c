HRESULT SetPropServer(
  [in] const BYTE       *pIDString,
  [in] DWORD            dwIDStringLen,
  [in] const MSAAPROPID *paProps,
  [in] int              cProps,
  [in] IAccPropServer   *pServer,
  [in] AnnoScope        annoScope
);