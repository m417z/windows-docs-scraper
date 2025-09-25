HRESULT _ExecChildren(
  [in]      IUnknown   *punkBar,
  [in]      BOOL       fBroadcast,
  [in]      const GUID *pguidCmdGroup,
  [in]      DWORD      nCmdID,
  [in]      DWORD      nCmdexecopt,
  [in]      VARIANTARG *pvarargIn,
  [in, out] VARIANTARG *pvarargOut
);