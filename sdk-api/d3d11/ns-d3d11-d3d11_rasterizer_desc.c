typedef struct D3D11_RASTERIZER_DESC {
  D3D11_FILL_MODE FillMode;
  D3D11_CULL_MODE CullMode;
  BOOL            FrontCounterClockwise;
  INT             DepthBias;
  FLOAT           DepthBiasClamp;
  FLOAT           SlopeScaledDepthBias;
  BOOL            DepthClipEnable;
  BOOL            ScissorEnable;
  BOOL            MultisampleEnable;
  BOOL            AntialiasedLineEnable;
} D3D11_RASTERIZER_DESC;