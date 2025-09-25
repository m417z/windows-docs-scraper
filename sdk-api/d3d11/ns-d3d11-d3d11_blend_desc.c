typedef struct D3D11_BLEND_DESC {
  BOOL                           AlphaToCoverageEnable;
  BOOL                           IndependentBlendEnable;
  D3D11_RENDER_TARGET_BLEND_DESC RenderTarget[8];
} D3D11_BLEND_DESC;