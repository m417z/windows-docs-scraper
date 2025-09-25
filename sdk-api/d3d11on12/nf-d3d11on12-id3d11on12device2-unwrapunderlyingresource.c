HRESULT UnwrapUnderlyingResource(
  [in]  ID3D11Resource     *pResource11,
  [in]  ID3D12CommandQueue *pCommandQueue,
  [in]  REFIID             riid,
  [out] void               **ppvResource12
);