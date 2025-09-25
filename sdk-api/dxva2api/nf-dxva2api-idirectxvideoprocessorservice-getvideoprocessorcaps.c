HRESULT GetVideoProcessorCaps(
  [in]  REFGUID                  VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc    *pVideoDesc,
  [in]  D3DFORMAT                RenderTargetFormat,
  [out] DXVA2_VideoProcessorCaps *pCaps
);