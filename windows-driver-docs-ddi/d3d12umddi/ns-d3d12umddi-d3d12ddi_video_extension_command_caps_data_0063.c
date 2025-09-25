typedef struct D3D12DDI_VIDEO_EXTENSION_COMMAND_CAPS_DATA_0063 {
  [in]  UINT       NodeIndex;
  [in]  GUID       CommandId;
  [in]  const void *pInputData;
  [in]  SIZE_T     InputDataSizeInBytes;
  [out] void       *pOutputData;
  [out] SIZE_T     OutputDataSizeInBytes;
} D3D12DDI_VIDEO_EXTENSION_COMMAND_CAPS_DATA_0063;