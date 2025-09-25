typedef struct D3D12_RASTERIZER_DESC {
  D3D12_FILL_MODE                       FillMode;
  D3D12_CULL_MODE                       CullMode;
  BOOL                                  FrontCounterClockwise;
  INT                                   DepthBias;
  FLOAT                                 DepthBiasClamp;
  FLOAT                                 SlopeScaledDepthBias;
  BOOL                                  DepthClipEnable;
  BOOL                                  MultisampleEnable;
  BOOL                                  AntialiasedLineEnable;
  UINT                                  ForcedSampleCount;
  D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster;
} D3D12_RASTERIZER_DESC;