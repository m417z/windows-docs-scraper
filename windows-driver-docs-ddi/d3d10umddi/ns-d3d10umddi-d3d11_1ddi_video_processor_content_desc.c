typedef struct D3D11_1DDI_VIDEO_PROCESSOR_CONTENT_DESC {
  D3D11_1DDI_VIDEO_FRAME_FORMAT InputFrameFormat;
  DXGI_RATIONAL                 InputFrameRate;
  UINT                          InputWidth;
  UINT                          InputHeight;
  DXGI_RATIONAL                 OutputFrameRate;
  UINT                          OutputWidth;
  UINT                          OutputHeight;
  D3D11_1DDI_VIDEO_USAGE        Usage;
} D3D11_1DDI_VIDEO_PROCESSOR_CONTENT_DESC;