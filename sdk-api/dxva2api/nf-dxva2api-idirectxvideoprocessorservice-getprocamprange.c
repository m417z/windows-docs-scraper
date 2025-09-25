HRESULT GetProcAmpRange(
  [in]  REFGUID               VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc *pVideoDesc,
  [in]  D3DFORMAT             RenderTargetFormat,
  [in]  UINT                  ProcAmpCap,
  [out] DXVA2_ValueRange      *pRange
);