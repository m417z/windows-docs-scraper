typedef struct D3D10_DEPTH_STENCIL_DESC {
  BOOL                       DepthEnable;
  D3D10_DEPTH_WRITE_MASK     DepthWriteMask;
  D3D10_COMPARISON_FUNC      DepthFunc;
  BOOL                       StencilEnable;
  UINT8                      StencilReadMask;
  UINT8                      StencilWriteMask;
  D3D10_DEPTH_STENCILOP_DESC FrontFace;
  D3D10_DEPTH_STENCILOP_DESC BackFace;
} D3D10_DEPTH_STENCIL_DESC;