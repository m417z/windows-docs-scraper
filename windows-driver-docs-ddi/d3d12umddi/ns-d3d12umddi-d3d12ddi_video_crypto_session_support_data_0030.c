typedef struct D3D12DDI_VIDEO_CRYPTO_SESSION_SUPPORT_DATA_0030 {
  UINT                                       NodeIndex;
  GUID                                       DecodeProfile;
  GUID                                       ContentProtectionSystem;
  D3D12DDI_CRYPTO_SESSION_FLAGS_0030         Flags;
  D3D12DDI_BITSTREAM_ENCRYPTION_TYPE_0030    BitstreamEncryption;
  UINT                                       KeyBaseDataSize;
  D3D12DDI_CRYPTO_SESSION_SUPPORT_FLAGS_0030 Support;
} D3D12DDI_VIDEO_CRYPTO_SESSION_SUPPORT_DATA_0030;