typedef struct D3D10_DDI_DEPTH_STENCIL_DESC {
  [in] BOOL                           DepthEnable;
  [in] D3D10_DDI_DEPTH_WRITE_MASK     DepthWriteMask;
  [in] D3D10_DDI_COMPARISON_FUNC      DepthFunc;
  [in] BOOL                           StencilEnable;
  [in] BOOL                           FrontEnable;
  [in] BOOL                           BackEnable;
  [in] UINT8                          StencilReadMask;
  [in] UINT8                          StencilWriteMask;
  [in] D3D10_DDI_DEPTH_STENCILOP_DESC FrontFace;
  [in] D3D10_DDI_DEPTH_STENCILOP_DESC BackFace;
} D3D10_DDI_DEPTH_STENCIL_DESC;