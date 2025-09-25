typedef struct D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SUPPORT {
  UINT       NodeIndex;
  GUID       CommandId;
  const void *pInputData;
  SIZE_T     InputDataSizeInBytes;
  void       *pOutputData;
  SIZE_T     OutputDataSizeInBytes;
} D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SUPPORT;