void VideoProcessorGetStreamOutputRate(
  [in]  ID3D11VideoProcessor              *pVideoProcessor,
  [in]  UINT                              StreamIndex,
  [out] D3D11_VIDEO_PROCESSOR_OUTPUT_RATE *pOutputRate,
  [out] BOOL                              *pRepeatFrame,
  [out] DXGI_RATIONAL                     *pCustomRate
);