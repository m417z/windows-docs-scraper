void CSGetConstantBuffers1(
  [in]            UINT         StartSlot,
  [in]            UINT         NumBuffers,
  [out, optional] ID3D11Buffer **ppConstantBuffers,
  [out, optional] UINT         *pFirstConstant,
  [out, optional] UINT         *pNumConstants
);