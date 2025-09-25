typedef struct D3D11_VIDEO_PROCESSOR_CUSTOM_RATE {
  DXGI_RATIONAL CustomRate;
  UINT          OutputFrames;
  BOOL          InputInterlaced;
  UINT          InputFramesOrFields;
} D3D11_VIDEO_PROCESSOR_CUSTOM_RATE;