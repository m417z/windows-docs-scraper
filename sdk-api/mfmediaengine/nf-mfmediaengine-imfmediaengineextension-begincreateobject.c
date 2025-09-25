HRESULT BeginCreateObject(
  [in]           BSTR             bstrURL,
  [in]           IMFByteStream    *pByteStream,
  [in]           MF_OBJECT_TYPE   type,
  [out]          IUnknown         **ppIUnknownCancelCookie,
  [in]           IMFAsyncCallback *pCallback,
  [in, optional] IUnknown         *punkState
);