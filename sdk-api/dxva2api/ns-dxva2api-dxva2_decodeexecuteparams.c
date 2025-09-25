typedef struct _DXVA2_DecodeExecuteParams {
  UINT                      NumCompBuffers;
  DXVA2_DecodeBufferDesc    *pCompressedBuffers;
  DXVA2_DecodeExtensionData *pExtensionData;
} DXVA2_DecodeExecuteParams;