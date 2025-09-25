HRESULT CreateVideoProcessor(
  [in]  REFGUID                VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc  *pVideoDesc,
  [in]  D3DFORMAT              RenderTargetFormat,
  [in]  UINT                   MaxNumSubStreams,
  [out] IDirectXVideoProcessor **ppVidProcess
);