typedef struct _DXVA2_DecodeExtensionData {
  UINT  Function;
  PVOID pPrivateInputData;
  UINT  PrivateInputDataSize;
  PVOID pPrivateOutputData;
  UINT  PrivateOutputDataSize;
} DXVA2_DecodeExtensionData;