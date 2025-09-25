HRESULT CreateInputLayout(
  [in]  const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs,
  [in]  UINT                           NumElements,
  [in]  const void                     *pShaderBytecodeWithInputSignature,
  [in]  SIZE_T                         BytecodeLength,
  [out] ID3D10InputLayout              **ppInputLayout
);