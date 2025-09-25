void VideoProcessorSetStreamPixelAspectRatio(
  [in] ID3D11VideoProcessor *pVideoProcessor,
  [in] UINT                 StreamIndex,
  [in] BOOL                 Enable,
  [in] const DXGI_RATIONAL  *pSourceAspectRatio,
  [in] const DXGI_RATIONAL  *pDestinationAspectRatio
);