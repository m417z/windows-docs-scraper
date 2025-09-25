HRESULT BeginCreateObject(
  [in]  LPCWSTR          pwszURL,
  [in]  DWORD            dwFlags,
  [in]  IPropertyStore   *pProps,
  [out] IUnknown         **ppIUnknownCancelCookie,
  [in]  IMFAsyncCallback *pCallback,
  [in]  IUnknown         *punkState
);