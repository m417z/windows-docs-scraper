typedef struct D3D10_DDI_DEPTH_STENCILOP_DESC {
  [in] D3D10_DDI_STENCIL_OP      StencilFailOp;
  [in] D3D10_DDI_STENCIL_OP      StencilDepthFailOp;
  [in] D3D10_DDI_STENCIL_OP      StencilPassOp;
  [in] D3D10_DDI_COMPARISON_FUNC StencilFunc;
} D3D10_DDI_DEPTH_STENCILOP_DESC;