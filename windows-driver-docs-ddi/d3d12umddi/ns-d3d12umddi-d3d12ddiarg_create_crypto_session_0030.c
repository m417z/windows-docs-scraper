typedef struct D3D12DDIARG_CREATE_CRYPTO_SESSION_0030 {
  UINT                                    NodeMask;
  GUID                                    DecodeProfile;
  GUID                                    ContentProtectionSystem;
  D3D12DDI_BITSTREAM_ENCRYPTION_TYPE_0030 BitstreamEncryption;
  D3D12DDI_CRYPTO_SESSION_FLAGS_0030      Flags;
} D3D12DDIARG_CREATE_CRYPTO_SESSION_0030;