HRESULT RespondToWinEvent(
  [in] DWORD                      idWinEvent,
  [in] HWND                       hwnd,
  [in] LONG                       idObject,
  [in] LONG                       idChild,
  [in] IProxyProviderWinEventSink *pSink
);