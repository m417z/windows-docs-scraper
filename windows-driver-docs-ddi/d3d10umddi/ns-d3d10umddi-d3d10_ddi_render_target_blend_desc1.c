typedef struct D3D10_DDI_RENDER_TARGET_BLEND_DESC1 {
  [in] BOOL               BlendEnable;
  [in] D3D10_DDI_BLEND    SrcBlend;
  [in] D3D10_DDI_BLEND    DestBlend;
  [in] D3D10_DDI_BLEND_OP BlendOp;
  [in] D3D10_DDI_BLEND    SrcBlendAlpha;
  [in] D3D10_DDI_BLEND    DestBlendAlpha;
  [in] D3D10_DDI_BLEND_OP BlendOpAlpha;
  [in] UINT8              RenderTargetWriteMask;
} D3D10_DDI_RENDER_TARGET_BLEND_DESC1;