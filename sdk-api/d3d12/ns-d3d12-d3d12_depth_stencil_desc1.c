typedef struct D3D12_DEPTH_STENCIL_DESC1 {
  BOOL                       DepthEnable;
  D3D12_DEPTH_WRITE_MASK     DepthWriteMask;
  D3D12_COMPARISON_FUNC      DepthFunc;
  BOOL                       StencilEnable;
  UINT8                      StencilReadMask;
  UINT8                      StencilWriteMask;
  D3D12_DEPTH_STENCILOP_DESC FrontFace;
  D3D12_DEPTH_STENCILOP_DESC BackFace;
  BOOL                       DepthBoundsTestEnable;
} D3D12_DEPTH_STENCIL_DESC1;