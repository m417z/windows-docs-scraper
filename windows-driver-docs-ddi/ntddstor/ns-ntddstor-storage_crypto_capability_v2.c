typedef struct _STORAGE_CRYPTO_CAPABILITY_V2 {
  ULONG                               Version;
  ULONG                               Size;
  ULONG                               CryptoCapabilityIndex;
  STORAGE_CRYPTO_ALGORITHM_ID         AlgorithmId;
  STORAGE_CRYPTO_KEY_SIZE             KeySize;
  ULONG                               DataUnitSizeBitmask;
  USHORT                              MaxIVBitSize;
  USHORT                              Reserved;
  STORAGE_SECURITY_COMPLIANCE_BITMASK SecurityComplianceBitmask;
} STORAGE_CRYPTO_CAPABILITY_V2, *PSTORAGE_CRYPTO_CAPABILITY_V2;