typedef struct D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT_DATA_0063 {
  [in]  GUID                                                  CommandId;
  [in]  D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063 Stage;
  [out] UINT                                                  ParameterCount;
  [out] UINT                                                  ParameterPacking;
} D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT_DATA_0063;