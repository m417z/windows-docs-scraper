HRESULT CreateClassInstance(
  [in]  LPCSTR              pClassTypeName,
  [in]  UINT                ConstantBufferOffset,
  [in]  UINT                ConstantVectorOffset,
  [in]  UINT                TextureOffset,
  [in]  UINT                SamplerOffset,
  [out] ID3D11ClassInstance **ppInstance
);