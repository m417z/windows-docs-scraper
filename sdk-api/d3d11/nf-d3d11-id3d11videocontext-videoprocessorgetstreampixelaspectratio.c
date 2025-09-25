void VideoProcessorGetStreamPixelAspectRatio(
  [in]  ID3D11VideoProcessor *pVideoProcessor,
  [in]  UINT                 StreamIndex,
  [out] BOOL                 *pEnabled,
  [out] DXGI_RATIONAL        *pSourceAspectRatio,
  [out] DXGI_RATIONAL        *pDestinationAspectRatio
);