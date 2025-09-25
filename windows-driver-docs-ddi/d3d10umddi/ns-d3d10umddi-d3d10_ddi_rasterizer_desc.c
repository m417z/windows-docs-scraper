typedef struct D3D10_DDI_RASTERIZER_DESC {
  [in] D3D10_DDI_FILL_MODE FillMode;
  [in] D3D10_DDI_CULL_MODE CullMode;
  [in] BOOL                FrontCounterClockwise;
  [in] INT32               DepthBias;
  [in] FLOAT               DepthBiasClamp;
  [in] FLOAT               SlopeScaledDepthBias;
  [in] BOOL                DepthClipEnable;
  [in] BOOL                ScissorEnable;
  [in] BOOL                MultisampleEnable;
  [in] BOOL                AntialiasedLineEnable;
} D3D10_DDI_RASTERIZER_DESC;