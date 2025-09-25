HRESULT GetVideoProcessorSubStreamFormats(
  [in]  REFGUID               VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc *pVideoDesc,
  [in]  D3DFORMAT             RenderTargetFormat,
  [out] UINT                  *pCount,
  [out] D3DFORMAT             **pFormats
);