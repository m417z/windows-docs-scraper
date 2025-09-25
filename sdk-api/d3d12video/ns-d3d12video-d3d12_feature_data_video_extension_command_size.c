typedef struct D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SIZE {
  UINT       NodeIndex;
  GUID       CommandId;
  const void *pCreationParameters;
  SIZE_T     CreationParametersSizeInBytes;
  UINT64     MemoryPoolL0Size;
  UINT64     MemoryPoolL1Size;
} D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SIZE;