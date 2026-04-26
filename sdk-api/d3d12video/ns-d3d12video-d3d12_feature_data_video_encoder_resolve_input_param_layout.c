typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT {
  UINT                                       NodeIndex;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO SessionInfo;
  D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE         MapType;
  BOOL                                       IsSupported;
  UINT64                                     MaxResolvedBufferAllocationSize;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLVE_INPUT_PARAM_LAYOUT;