void VideoProcessorGetStreamStereoFormat(
  [in]  ID3D11VideoProcessor                   *pVideoProcessor,
  [in]  UINT                                   StreamIndex,
  [out] BOOL                                   *pEnable,
  [out] D3D11_VIDEO_PROCESSOR_STEREO_FORMAT    *pFormat,
  [out] BOOL                                   *pLeftViewFrame0,
  [out] BOOL                                   *pBaseViewFrame0,
  [out] D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE *pFlipMode,
  [out] int                                    *MonoOffset
);