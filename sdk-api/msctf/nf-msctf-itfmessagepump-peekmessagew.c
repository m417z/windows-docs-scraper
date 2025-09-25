HRESULT PeekMessageW(
  [out] LPMSG pMsg,
  [in]  HWND  hwnd,
  [in]  UINT  wMsgFilterMin,
  [in]  UINT  wMsgFilterMax,
  [in]  UINT  wRemoveMsg,
  [out] BOOL  *pfResult
);