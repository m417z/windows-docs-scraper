typedef struct D3D11_DEPTH_STENCIL_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_DSV_DIMENSION ViewDimension;
  UINT                Flags;
  union {
    D3D11_TEX1D_DSV         Texture1D;
    D3D11_TEX1D_ARRAY_DSV   Texture1DArray;
    D3D11_TEX2D_DSV         Texture2D;
    D3D11_TEX2D_ARRAY_DSV   Texture2DArray;
    D3D11_TEX2DMS_DSV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_DSV Texture2DMSArray;
  };
} D3D11_DEPTH_STENCIL_VIEW_DESC;