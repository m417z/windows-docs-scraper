void VideoProcessorSetStreamStereoFormat(
  [in] ID3D11VideoProcessor                   *pVideoProcessor,
  [in] UINT                                   StreamIndex,
  [in] BOOL                                   Enable,
  [in] D3D11_VIDEO_PROCESSOR_STEREO_FORMAT    Format,
  [in] BOOL                                   LeftViewFrame0,
  [in] BOOL                                   BaseViewFrame0,
  [in] D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE FlipMode,
  [in] int                                    MonoOffset
);