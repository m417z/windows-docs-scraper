HRESULT D3D10CreateEffectFromMemory(
  [in]  void             *pData,
  [in]  SIZE_T           DataLength,
  [in]  UINT             FXFlags,
  [in]  ID3D10Device     *pDevice,
  [in]  ID3D10EffectPool *pEffectPool,
  [out] ID3D10Effect     **ppEffect
);