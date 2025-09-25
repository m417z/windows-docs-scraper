typedef struct D3D11_RENDER_TARGET_VIEW_DESC1 {
  DXGI_FORMAT         Format;
  D3D11_RTV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_RTV        Buffer;
    D3D11_TEX1D_RTV         Texture1D;
    D3D11_TEX1D_ARRAY_RTV   Texture1DArray;
    D3D11_TEX2D_RTV1        Texture2D;
    D3D11_TEX2D_ARRAY_RTV1  Texture2DArray;
    D3D11_TEX2DMS_RTV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_RTV Texture2DMSArray;
    D3D11_TEX3D_RTV         Texture3D;
  };
} D3D11_RENDER_TARGET_VIEW_DESC1;