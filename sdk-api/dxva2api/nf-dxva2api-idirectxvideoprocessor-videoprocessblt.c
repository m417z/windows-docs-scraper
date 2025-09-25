HRESULT VideoProcessBlt(
  [in]  IDirect3DSurface9                 *pRenderTarget,
  [in]  const DXVA2_VideoProcessBltParams *pBltParams,
  [in]  const DXVA2_VideoSample           *pSamples,
  [in]  UINT                              NumSamples,
  [out] HANDLE                            *pHandleComplete
);