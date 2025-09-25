HRESULT RecommendVideoDecoderDownsampleParameters(
  [in]  const D3D11_VIDEO_DECODER_DESC   *pInputDesc,
  [in]  DXGI_COLOR_SPACE_TYPE            InputColorSpace,
  [in]  const D3D11_VIDEO_DECODER_CONFIG *pInputConfig,
  [in]  const DXGI_RATIONAL              *pFrameRate,
  [out] D3D11_VIDEO_SAMPLE_DESC          *pRecommendedOutputDesc
);