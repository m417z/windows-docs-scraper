void CD3D11_SHADER_RESOURCE_VIEW_DESC(
  ID3D11Texture1D     *pTex1D,
  D3D11_SRV_DIMENSION viewDimension,
  DXGI_FORMAT         format,
  UINT                mostDetailedMip,
  UINT                mipLevels,
  UINT                firstArraySlice,
  UINT                arraySize
);