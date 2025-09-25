HRESULT SetHmenuPropServer(
  [in] HMENU            hmenu,
  [in] DWORD            idChild,
  [in] const MSAAPROPID *paProps,
  [in] int              cProps,
  [in] IAccPropServer   *pServer,
  [in] AnnoScope        annoScope
);