struct CD3D11_RASTERIZER_DESC : D3D11_RASTERIZER_DESC {
  void CD3D11_RASTERIZER_DESC();
  void CD3D11_RASTERIZER_DESC(
    const D3D11_RASTERIZER_DESC & o
  );
  void CD3D11_RASTERIZER_DESC(
    CD3D11_DEFAULT unnamedParam1
  );
  void CD3D11_RASTERIZER_DESC(
    D3D11_FILL_MODE fillMode,
    D3D11_CULL_MODE cullMode,
    BOOL            frontCounterClockwise,
    INT             depthBias,
    FLOAT           depthBiasClamp,
    FLOAT           slopeScaledDepthBias,
    BOOL            depthClipEnable,
    BOOL            scissorEnable,
    BOOL            multisampleEnable,
    BOOL            antialiasedLineEnable
  );
  void ~CD3D11_RASTERIZER_DESC();
};