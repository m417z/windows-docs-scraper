typedef struct D3D11_UNORDERED_ACCESS_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_UAV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_UAV      Buffer;
    D3D11_TEX1D_UAV       Texture1D;
    D3D11_TEX1D_ARRAY_UAV Texture1DArray;
    D3D11_TEX2D_UAV       Texture2D;
    D3D11_TEX2D_ARRAY_UAV Texture2DArray;
    D3D11_TEX3D_UAV       Texture3D;
  };
} D3D11_UNORDERED_ACCESS_VIEW_DESC;