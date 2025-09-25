void VideoProcessorSetStreamOutputRate(
  [in] ID3D11VideoProcessor              *pVideoProcessor,
  [in] UINT                              StreamIndex,
  [in] D3D11_VIDEO_PROCESSOR_OUTPUT_RATE OutputRate,
  [in] BOOL                              RepeatFrame,
  [in] const DXGI_RATIONAL               *pCustomRate
);