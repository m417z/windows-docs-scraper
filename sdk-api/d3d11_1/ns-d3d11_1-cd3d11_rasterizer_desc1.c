struct CD3D11_RASTERIZER_DESC1 : D3D11_RASTERIZER_DESC1 {
  void CD3D11_RASTERIZER_DESC1();
  void CD3D11_RASTERIZER_DESC1(
    const D3D11_RASTERIZER_DESC1 & o
  );
  void CD3D11_RASTERIZER_DESC1(
    CD3D11_DEFAULT unnamedParam1
  );
  void CD3D11_RASTERIZER_DESC1(
    D3D11_FILL_MODE fillMode,
    D3D11_CULL_MODE cullMode,
    BOOL            frontCounterClockwise,
    INT             depthBias,
    FLOAT           depthBiasClamp,
    FLOAT           slopeScaledDepthBias,
    BOOL            depthClipEnable,
    BOOL            scissorEnable,
    BOOL            multisampleEnable,
    BOOL            antialiasedLineEnable,
    UINT            forcedSampleCount
  );
  void ~CD3D11_RASTERIZER_DESC1();
};