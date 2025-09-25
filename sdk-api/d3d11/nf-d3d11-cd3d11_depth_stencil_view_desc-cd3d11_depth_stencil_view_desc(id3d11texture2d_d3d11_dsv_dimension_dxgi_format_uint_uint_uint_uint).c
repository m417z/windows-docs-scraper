void CD3D11_DEPTH_STENCIL_VIEW_DESC(
  ID3D11Texture2D     *pTex2D,
  D3D11_DSV_DIMENSION viewDimension,
  DXGI_FORMAT         format,
  UINT                mipSlice,
  UINT                firstArraySlice,
  UINT                arraySize,
  UINT                flags
);