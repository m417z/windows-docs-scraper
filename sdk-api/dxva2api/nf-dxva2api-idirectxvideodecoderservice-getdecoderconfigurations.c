HRESULT GetDecoderConfigurations(
  [in]  REFGUID                   Guid,
  [in]  const DXVA2_VideoDesc     *pVideoDesc,
  [in]  void                      *pReserved,
  [out] UINT                      *pCount,
  [out] DXVA2_ConfigPictureDecode **ppConfigs
);