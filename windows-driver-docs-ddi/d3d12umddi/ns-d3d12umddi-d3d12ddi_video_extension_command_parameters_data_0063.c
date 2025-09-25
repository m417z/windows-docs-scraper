typedef struct D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETERS_DATA_0063 {
  [in]  GUID                                                  CommandId;
  [in]  D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063 Stage;
  [in]  UINT                                                  ParameterCount;
  [out] D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_INFO_0063  *pParameterInfos;
} D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETERS_DATA_0063;