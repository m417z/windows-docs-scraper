void CSSetConstantBuffers1(
  [in]           UINT         StartSlot,
  [in]           UINT         NumBuffers,
  [in, optional] ID3D11Buffer * const *ppConstantBuffers,
  [in, optional] const UINT   *pFirstConstant,
  [in, optional] const UINT   *pNumConstants
);