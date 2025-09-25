typedef struct D3D11_VIDEO_PROCESSOR_STREAM {
  BOOL                          Enable;
  UINT                          OutputIndex;
  UINT                          InputFrameOrField;
  UINT                          PastFrames;
  UINT                          FutureFrames;
  ID3D11VideoProcessorInputView **ppPastSurfaces;
  ID3D11VideoProcessorInputView *pInputSurface;
  ID3D11VideoProcessorInputView **ppFutureSurfaces;
  ID3D11VideoProcessorInputView **ppPastSurfacesRight;
  ID3D11VideoProcessorInputView *pInputSurfaceRight;
  ID3D11VideoProcessorInputView **ppFutureSurfacesRight;
} D3D11_VIDEO_PROCESSOR_STREAM;