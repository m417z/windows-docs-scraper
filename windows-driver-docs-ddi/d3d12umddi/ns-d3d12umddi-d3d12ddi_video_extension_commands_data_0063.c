typedef struct D3D12DDI_VIDEO_EXTENSION_COMMANDS_DATA_0063 {
  [in]  UINT                                       NodeIndex;
  [in]  UINT                                       CommandCount;
  [out] D3D12DDI_VIDEO_EXTENSION_COMMAND_INFO_0063 *pCommandInfos;
} D3D12DDI_VIDEO_EXTENSION_COMMANDS_DATA_0063;