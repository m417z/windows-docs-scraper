typedef struct D3D10_SHADER_RESOURCE_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D10_SRV_DIMENSION ViewDimension;
  union {
    D3D10_BUFFER_SRV        Buffer;
    D3D10_TEX1D_SRV         Texture1D;
    D3D10_TEX1D_ARRAY_SRV   Texture1DArray;
    D3D10_TEX2D_SRV         Texture2D;
    D3D10_TEX2D_ARRAY_SRV   Texture2DArray;
    D3D10_TEX2DMS_SRV       Texture2DMS;
    D3D10_TEX2DMS_ARRAY_SRV Texture2DMSArray;
    D3D10_TEX3D_SRV         Texture3D;
    D3D10_TEXCUBE_SRV       TextureCube;
  };
} D3D10_SHADER_RESOURCE_VIEW_DESC;