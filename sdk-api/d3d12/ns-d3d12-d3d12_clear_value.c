typedef struct D3D12_CLEAR_VALUE {
  DXGI_FORMAT Format;
  union {
    FLOAT                     Color[4];
    D3D12_DEPTH_STENCIL_VALUE DepthStencil;
  };
} D3D12_CLEAR_VALUE;