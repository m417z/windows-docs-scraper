typedef struct D3D12DDI_CLEAR_VALUES {
  DXGI_FORMAT Format;
  union {
    FLOAT                         Color[4];
    D3D12DDI_DEPTH_STENCIL_VALUES DepthStencil;
  };
} D3D12DDI_CLEAR_VALUES;