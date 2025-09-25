typedef struct D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMANDS {
  UINT                               NodeIndex;
  UINT                               CommandCount;
  D3D12_VIDEO_EXTENSION_COMMAND_INFO *pCommandInfos;
} D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMANDS;