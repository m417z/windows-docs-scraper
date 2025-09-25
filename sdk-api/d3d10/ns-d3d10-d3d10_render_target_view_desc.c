typedef struct D3D10_RENDER_TARGET_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D10_RTV_DIMENSION ViewDimension;
  union {
    D3D10_BUFFER_RTV        Buffer;
    D3D10_TEX1D_RTV         Texture1D;
    D3D10_TEX1D_ARRAY_RTV   Texture1DArray;
    D3D10_TEX2D_RTV         Texture2D;
    D3D10_TEX2D_ARRAY_RTV   Texture2DArray;
    D3D10_TEX2DMS_RTV       Texture2DMS;
    D3D10_TEX2DMS_ARRAY_RTV Texture2DMSArray;
    D3D10_TEX3D_RTV         Texture3D;
  };
} D3D10_RENDER_TARGET_VIEW_DESC;