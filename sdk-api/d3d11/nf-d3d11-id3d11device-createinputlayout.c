HRESULT CreateInputLayout(
  [in]            const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs,
  [in]            UINT                           NumElements,
  [in]            const void                     *pShaderBytecodeWithInputSignature,
  [in]            SIZE_T                         BytecodeLength,
  [out, optional] ID3D11InputLayout              **ppInputLayout
);