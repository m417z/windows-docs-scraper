typedef struct D3D11_1_DDI_BLEND_DESC {
  [in] BOOL                                 AlphaToCoverageEnable;
  [in] BOOL                                 IndependentBlendEnable;
       D3D11_1_DDI_RENDER_TARGET_BLEND_DESC RenderTarget[D3D10_DDI_SIMULTANEOUS_RENDER_TARGET_COUNT];
} D3D11_1_DDI_BLEND_DESC;