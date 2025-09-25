typedef struct D3D11_RENDER_TARGET_BLEND_DESC1 {
  BOOL           BlendEnable;
  BOOL           LogicOpEnable;
  D3D11_BLEND    SrcBlend;
  D3D11_BLEND    DestBlend;
  D3D11_BLEND_OP BlendOp;
  D3D11_BLEND    SrcBlendAlpha;
  D3D11_BLEND    DestBlendAlpha;
  D3D11_BLEND_OP BlendOpAlpha;
  D3D11_LOGIC_OP LogicOp;
  UINT8          RenderTargetWriteMask;
} D3D11_RENDER_TARGET_BLEND_DESC1;