typedef struct D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING {
  [in]  const D3D11_1DDI_VIDEO_DECODER_DESC   *pInputDesc;
  [in]  D3DDDI_COLOR_SPACE_TYPE               InputColorSpace;
  [in]  const D3D11_1DDI_VIDEO_DECODER_CONFIG *pInputConfig;
  [in]  const DXGI_RATIONAL                   *pFrameRate;
  [in]  const D3D11_1DDI_VIDEO_DECODER_DESC   *pOutputDesc;
  [in]  D3DDDI_COLOR_SPACE_TYPE               OutputColorSpace;
  [out] BOOL                                  Supported;
  [out] BOOL                                  RealTime;
} D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING;