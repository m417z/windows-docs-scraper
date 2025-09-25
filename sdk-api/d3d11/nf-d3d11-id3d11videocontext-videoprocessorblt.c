HRESULT VideoProcessorBlt(
  [in] ID3D11VideoProcessor               *pVideoProcessor,
  [in] ID3D11VideoProcessorOutputView     *pView,
  [in] UINT                               OutputFrame,
  [in] UINT                               StreamCount,
  [in] const D3D11_VIDEO_PROCESSOR_STREAM *pStreams
);