HRESULT VideoProcessorGetBehaviorHints(
  [in]  ID3D11VideoProcessor                             *pVideoProcessor,
  [in]  UINT                                             OutputWidth,
  [in]  UINT                                             OutputHeight,
  [in]  DXGI_FORMAT                                      OutputFormat,
  [in]  UINT                                             StreamCount,
  [in]  const D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT *pStreams,
  [out] UINT                                             *pBehaviorHints
);