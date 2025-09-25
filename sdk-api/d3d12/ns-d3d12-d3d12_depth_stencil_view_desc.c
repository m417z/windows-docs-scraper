typedef struct D3D12_DEPTH_STENCIL_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D12_DSV_DIMENSION ViewDimension;
  D3D12_DSV_FLAGS     Flags;
  union {
    D3D12_TEX1D_DSV         Texture1D;
    D3D12_TEX1D_ARRAY_DSV   Texture1DArray;
    D3D12_TEX2D_DSV         Texture2D;
    D3D12_TEX2D_ARRAY_DSV   Texture2DArray;
    D3D12_TEX2DMS_DSV       Texture2DMS;
    D3D12_TEX2DMS_ARRAY_DSV Texture2DMSArray;
  };
} D3D12_DEPTH_STENCIL_VIEW_DESC;