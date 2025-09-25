typedef struct D3D12DDI_VIDEO_DECODE_DECRYPTION_ARGUMENTS_0030 {
  D3D12DDI_HCRYPTOSESSIONPOLICY_0030 hDrvCryptoSessionPolicy;
  const VOID                         *pIV;
  UINT                               IVSize;
  const VOID                         *pSubSampleMappingBlock;
  UINT                               SubSampleMappingCount;
} D3D12DDI_VIDEO_DECODE_DECRYPTION_ARGUMENTS_0030;