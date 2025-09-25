typedef struct D3D12_RENDER_TARGET_BLEND_DESC {
  BOOL           BlendEnable;
  BOOL           LogicOpEnable;
  D3D12_BLEND    SrcBlend;
  D3D12_BLEND    DestBlend;
  D3D12_BLEND_OP BlendOp;
  D3D12_BLEND    SrcBlendAlpha;
  D3D12_BLEND    DestBlendAlpha;
  D3D12_BLEND_OP BlendOpAlpha;
  D3D12_LOGIC_OP LogicOp;
  UINT8          RenderTargetWriteMask;
} D3D12_RENDER_TARGET_BLEND_DESC;