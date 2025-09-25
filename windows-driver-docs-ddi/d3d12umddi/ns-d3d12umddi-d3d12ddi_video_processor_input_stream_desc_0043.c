typedef struct D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0043 {
  DXGI_FORMAT                                   Format;
  DXGI_COLOR_SPACE_TYPE                         ColorSpace;
  DXGI_RATIONAL                                 SourceAspectRatio;
  DXGI_RATIONAL                                 DestinationAspectRatio;
  DXGI_RATIONAL                                 FrameRate;
  D3D12DDI_VIDEO_SIZE_RANGE_0032                SourceSizeRange;
  D3D12DDI_VIDEO_SIZE_RANGE_0032                DestinationSizeRange;
  BOOL                                          EnableOrientation;
  D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS_0020      FilterFlags;
  D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020       StereoFormat;
  D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS_0020 DeinterlaceMode;
  BOOL                                          EnableAlphaBlending;
  D3D12DDI_VIDEO_PROCESS_LUMA_KEY_0020          LumaKey;
  UINT                                          NumPastFrames;
  UINT                                          NumFutureFrames;
  BOOL                                          EnableAutoProcessing;
} D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0043;