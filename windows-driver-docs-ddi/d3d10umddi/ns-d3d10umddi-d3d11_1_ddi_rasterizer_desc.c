typedef struct D3D11_1_DDI_RASTERIZER_DESC {
  [in] D3D10_DDI_FILL_MODE FillMode;
  [in] D3D10_DDI_CULL_MODE CullMode;
  [in] BOOL                FrontCounterClockwise;
  [in] INT                 DepthBias;
  [in] FLOAT               DepthBiasClamp;
  [in] FLOAT               SlopeScaledDepthBias;
  [in] BOOL                DepthClipEnable;
  [in] BOOL                ScissorEnable;
  [in] BOOL                MultisampleEnable;
  [in] BOOL                AntialiasedLineEnable;
  [in] UINT                ForcedSampleCount;
} D3D11_1_DDI_RASTERIZER_DESC;