typedef struct D3D11_DEPTH_STENCIL_DESC {
  BOOL                       DepthEnable;
  D3D11_DEPTH_WRITE_MASK     DepthWriteMask;
  D3D11_COMPARISON_FUNC      DepthFunc;
  BOOL                       StencilEnable;
  UINT8                      StencilReadMask;
  UINT8                      StencilWriteMask;
  D3D11_DEPTH_STENCILOP_DESC FrontFace;
  D3D11_DEPTH_STENCILOP_DESC BackFace;
} D3D11_DEPTH_STENCIL_DESC;