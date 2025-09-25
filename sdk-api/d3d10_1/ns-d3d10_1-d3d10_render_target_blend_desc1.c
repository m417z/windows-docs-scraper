typedef struct D3D10_RENDER_TARGET_BLEND_DESC1 {
  BOOL           BlendEnable;
  D3D10_BLEND    SrcBlend;
  D3D10_BLEND    DestBlend;
  D3D10_BLEND_OP BlendOp;
  D3D10_BLEND    SrcBlendAlpha;
  D3D10_BLEND    DestBlendAlpha;
  D3D10_BLEND_OP BlendOpAlpha;
  UINT8          RenderTargetWriteMask;
} D3D10_RENDER_TARGET_BLEND_DESC1;