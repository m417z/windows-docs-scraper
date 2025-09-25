typedef struct D3D11_1_DDI_RENDER_TARGET_BLEND_DESC {
  [in] BOOL                 BlendEnable;
       BOOL                 LogicOpEnable;
  [in] D3D10_DDI_BLEND      SrcBlend;
  [in] D3D10_DDI_BLEND      DestBlend;
  [in] D3D10_DDI_BLEND_OP   BlendOp;
  [in] D3D10_DDI_BLEND      SrcBlendAlpha;
  [in] D3D10_DDI_BLEND      DestBlendAlpha;
  [in] D3D10_DDI_BLEND_OP   BlendOpAlpha;
  [in] D3D11_1_DDI_LOGIC_OP LogicOp;
  [in] UINT8                RenderTargetWriteMask;
} D3D11_1_DDI_RENDER_TARGET_BLEND_DESC;