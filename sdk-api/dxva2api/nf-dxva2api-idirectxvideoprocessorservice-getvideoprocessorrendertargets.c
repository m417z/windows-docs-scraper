HRESULT GetVideoProcessorRenderTargets(
  [in]  REFGUID               VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc *pVideoDesc,
  [out] UINT                  *pCount,
  [out] D3DFORMAT             **pFormats
);