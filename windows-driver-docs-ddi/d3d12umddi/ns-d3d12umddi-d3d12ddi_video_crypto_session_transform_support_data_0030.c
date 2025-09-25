typedef struct D3D12DDI_VIDEO_CRYPTO_SESSION_TRANSFORM_SUPPORT_DATA_0030 {
  UINT                                                 NodeIndex;
  GUID                                                 DecodeProfile;
  GUID                                                 ContentProtectionSystem;
  D3D12DDI_CRYPTO_SESSION_FLAGS_0030                   Flags;
  D3D12DDI_BITSTREAM_ENCRYPTION_TYPE_0030              BitstreamEncryption;
  D3D12DDI_CRYPTO_SESSION_TRANSFORM_OPERATION_0030     Operation;
  BOOL                                                 ProtectedOutputRequired;
  UINT64                                               InputAlignment;
  UINT64                                               InputPreambleSize;
  UINT64                                               OutputAlignment;
  UINT64                                               OutputPreambleSize;
  D3D12DDI_CRYPTO_SESSION_TRANSFORM_SUPPORT_FLAGS_0030 Support;
} D3D12DDI_VIDEO_CRYPTO_SESSION_TRANSFORM_SUPPORT_DATA_0030;