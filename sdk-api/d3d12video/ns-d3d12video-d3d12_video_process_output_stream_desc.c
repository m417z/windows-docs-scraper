typedef struct D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC {
  DXGI_FORMAT                         Format;
  DXGI_COLOR_SPACE_TYPE               ColorSpace;
  D3D12_VIDEO_PROCESS_ALPHA_FILL_MODE AlphaFillMode;
  UINT                                AlphaFillModeSourceStreamIndex;
  FLOAT                               BackgroundColor[4];
  DXGI_RATIONAL                       FrameRate;
  BOOL                                EnableStereo;
} D3D12_VIDEO_PROCESS_OUTPUT_STREAM_DESC;