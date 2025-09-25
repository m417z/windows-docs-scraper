typedef struct D3D12DDI_VIDEO_EXTENSION_COMMAND_SIZE_DATA_0063 {
  [in]  UINT       NodeIndex;
  [in]  GUID       CommandId;
  [in]  const void *pCreationParameters;
  [in]  SIZE_T     CreationParametersSizeInBytes;
  [out] UINT64     MemoryPoolL0Size;
  [out] UINT64     MemoryPoolL1Size;
} D3D12DDI_VIDEO_EXTENSION_COMMAND_SIZE_DATA_0063;