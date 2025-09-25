void VideoProcessorGetStreamFilter(
  [in]  ID3D11VideoProcessor         *pVideoProcessor,
  [in]  UINT                         StreamIndex,
  [in]  D3D11_VIDEO_PROCESSOR_FILTER Filter,
  [out] BOOL                         *pEnabled,
  [out] int                          *pLevel
);