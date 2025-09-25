typedef struct D3D10_BLEND_DESC {
  BOOL           AlphaToCoverageEnable;
  BOOL           BlendEnable[8];
  D3D10_BLEND    SrcBlend;
  D3D10_BLEND    DestBlend;
  D3D10_BLEND_OP BlendOp;
  D3D10_BLEND    SrcBlendAlpha;
  D3D10_BLEND    DestBlendAlpha;
  D3D10_BLEND_OP BlendOpAlpha;
  UINT8          RenderTargetWriteMask[8];
} D3D10_BLEND_DESC;