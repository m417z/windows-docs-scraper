struct CD3D11_RASTERIZER_DESC2 : D3D11_RASTERIZER_DESC2 {
  void CD3D11_RASTERIZER_DESC2();
  void CD3D11_RASTERIZER_DESC2(
    const D3D11_RASTERIZER_DESC2 & o
  );
  void CD3D11_RASTERIZER_DESC2(
    CD3D11_DEFAULT unnamedParam1
  );
  void CD3D11_RASTERIZER_DESC2(
    D3D11_FILL_MODE                       fillMode,
    D3D11_CULL_MODE                       cullMode,
    BOOL                                  frontCounterClockwise,
    INT                                   depthBias,
    FLOAT                                 depthBiasClamp,
    FLOAT                                 slopeScaledDepthBias,
    BOOL                                  depthClipEnable,
    BOOL                                  scissorEnable,
    BOOL                                  multisampleEnable,
    BOOL                                  antialiasedLineEnable,
    UINT                                  forcedSampleCount,
    D3D11_CONSERVATIVE_RASTERIZATION_MODE conservativeRaster
  );
  void ~CD3D11_RASTERIZER_DESC2();
};