typedef struct D3D10_DDI_BLEND_DESC {
  [in] BOOL               AlphaToCoverageEnable;
       BOOL               BlendEnable[D3D10_DDI_SIMULTANEOUS_RENDER_TARGET_COUNT];
  [in] D3D10_DDI_BLEND    SrcBlend;
  [in] D3D10_DDI_BLEND    DestBlend;
  [in] D3D10_DDI_BLEND_OP BlendOp;
  [in] D3D10_DDI_BLEND    SrcBlendAlpha;
  [in] D3D10_DDI_BLEND    DestBlendAlpha;
  [in] D3D10_DDI_BLEND_OP BlendOpAlpha;
       UINT8              RenderTargetWriteMask[D3D10_DDI_SIMULTANEOUS_RENDER_TARGET_COUNT];
} D3D10_DDI_BLEND_DESC;