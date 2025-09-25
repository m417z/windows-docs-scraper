HRESULT CreateContext(
  [in]  TfClientId   tidOwner,
  [in]  DWORD        dwFlags,
  [in]  IUnknown     *punk,
  [out] ITfContext   **ppic,
  [out] TfEditCookie *pecTextStore
);