typedef struct D3D11_1DDI_VIDEO_PROCESSOR_STREAM {
  BOOL                                Enable;
  UINT                                OutputIndex;
  UINT                                InputFrameOrField;
  UINT                                PastFrames;
  UINT                                FutureFrames;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW *pPastSurfaces;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW hInputSurface;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW *pFutureSurfaces;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW *pPastSurfacesRight;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW hInputSurfaceRight;
  D3D11_1DDI_HVIDEOPROCESSORINPUTVIEW *pFutureSurfacesRight;
} D3D11_1DDI_VIDEO_PROCESSOR_STREAM;