typedef struct D3D12DDI_CRYPTO_SESSION_TRANSFORM_DECRYPT_HEADER_INPUT_ARGUMENTS_0030 {
  BOOL        Enable;
  const void  *pSliceHeaders;
  UINT64      SliceHeadersSize;
  const DWORD *pSliceHeadersOffsets;
  UINT64      SliceHeaderCount;
  const void  *pContext;
  UINT64      ContextSize;
} D3D12DDI_CRYPTO_SESSION_TRANSFORM_DECRYPT_HEADER_INPUT_ARGUMENTS_0030;