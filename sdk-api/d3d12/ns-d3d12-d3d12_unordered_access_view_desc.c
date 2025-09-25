typedef struct D3D12_UNORDERED_ACCESS_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D12_UAV_DIMENSION ViewDimension;
  union {
    D3D12_BUFFER_UAV        Buffer;
    D3D12_TEX1D_UAV         Texture1D;
    D3D12_TEX1D_ARRAY_UAV   Texture1DArray;
    D3D12_TEX2D_UAV         Texture2D;
    D3D12_TEX2D_ARRAY_UAV   Texture2DArray;
    D3D12_TEX2DMS_UAV       Texture2DMS;
    D3D12_TEX2DMS_ARRAY_UAV Texture2DMSArray;
    D3D12_TEX3D_UAV         Texture3D;
  };
} D3D12_UNORDERED_ACCESS_VIEW_DESC;