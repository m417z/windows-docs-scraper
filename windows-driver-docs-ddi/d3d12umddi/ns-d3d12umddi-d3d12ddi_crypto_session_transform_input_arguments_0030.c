typedef struct D3D12DDI_CRYPTO_SESSION_TRANSFORM_INPUT_ARGUMENTS_0030 {
  D3D12DDI_HCRYPTOSESSIONPOLICY_0030                                    hDrvCryptoSessionPolicy;
  D3D12DDI_HRESOURCE                                                    hDrvBuffer;
  UINT64                                                                Size;
  UINT64                                                                Offset;
  const void                                                            *pIV;
  UINT                                                                  IVSize;
  const void                                                            *pSubSampleMappingBlock;
  UINT                                                                  SubSampleMappingCount;
  const void                                                            *pContext;
  UINT64                                                                ContextSize;
  D3D12DDI_CRYPTO_SESSION_TRANSFORM_DECRYPT_HEADER_INPUT_ARGUMENTS_0030 EncryptedHeader;
} D3D12DDI_CRYPTO_SESSION_TRANSFORM_INPUT_ARGUMENTS_0030;