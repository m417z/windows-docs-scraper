HRESULT GetFilterPropertyRange(
  [in]  REFGUID               VideoProcDeviceGuid,
  [in]  const DXVA2_VideoDesc *pVideoDesc,
  [in]  D3DFORMAT             RenderTargetFormat,
  [in]  UINT                  FilterSetting,
  [out] DXVA2_ValueRange      *pRange
);