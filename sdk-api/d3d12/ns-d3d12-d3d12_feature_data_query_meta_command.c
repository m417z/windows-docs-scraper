typedef struct D3D12_FEATURE_DATA_QUERY_META_COMMAND {
  GUID       CommandId;
  UINT       NodeMask;
  const void *pQueryInputData;
  SIZE_T     QueryInputDataSizeInBytes;
  void       *pQueryOutputData;
  SIZE_T     QueryOutputDataSizeInBytes;
} D3D12_FEATURE_DATA_QUERY_META_COMMAND;