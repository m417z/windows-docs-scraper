typedef struct D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT {
  GUID                                          CommandId;
  D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE Stage;
  UINT                                          ParameterCount;
  UINT                                          ParameterPacking;
} D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT;