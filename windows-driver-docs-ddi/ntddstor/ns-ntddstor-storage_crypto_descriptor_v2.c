typedef struct _STORAGE_CRYPTO_DESCRIPTOR_V2 {
  ULONG                               Version;
  ULONG                               Size;
  ULONG                               NumKeysSupported;
  ULONG                               NumCryptoCapabilities;
  STORAGE_ICE_TYPE                    IceType;
  STORAGE_SECURITY_COMPLIANCE_BITMASK SecurityComplianceBitmask;
  STORAGE_CRYPTO_KEY_TYPE             KeyTypeBitmask;
  STORAGE_CRYPTO_CAPABILITY_V2        CryptoCapabilities[ANYSIZE_ARRAY];
} STORAGE_CRYPTO_DESCRIPTOR_V2, *PSTORAGE_CRYPTO_DESCRIPTOR_V2;