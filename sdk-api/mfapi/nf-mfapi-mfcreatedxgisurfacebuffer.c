HRESULT MFCreateDXGISurfaceBuffer(
  [in]  REFIID         riid,
  [in]  IUnknown       *punkSurface,
  [in]  UINT           uSubresourceIndex,
  [in]  BOOL           fBottomUpWhenLinear,
  [out] IMFMediaBuffer **ppBuffer
);