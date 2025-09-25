typedef struct D3D10_BLEND_DESC1 {
  BOOL                            AlphaToCoverageEnable;
  BOOL                            IndependentBlendEnable;
  D3D10_RENDER_TARGET_BLEND_DESC1 RenderTarget[8];
} D3D10_BLEND_DESC1;