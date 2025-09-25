HRESULT SetTimer(
  [in]  DWORD            dwFlags,
  [in]  LONGLONG         llClockTime,
  [in]  IMFAsyncCallback *pCallback,
  [in]  IUnknown         *punkState,
  [out] IUnknown         **ppunkKey
);