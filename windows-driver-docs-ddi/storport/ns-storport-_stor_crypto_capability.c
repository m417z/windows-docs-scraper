typedef struct _STOR_CRYPTO_CAPABILITY {
  ULONG                               Version;
  ULONG                               Size;
  USHORT                              CryptoCapabilityIndex;
  USHORT                              DataUnitSizeBitmask;
  STORAGE_CRYPTO_ALGORITHM_ID         AlgorithmId;
  STORAGE_CRYPTO_KEY_SIZE             KeySize;
  USHORT                              MaxIVBitSize;
  USHORT                              Reserved;
  STORAGE_SECURITY_COMPLIANCE_BITMASK SecurityComplianceBitmask;
} STOR_CRYPTO_CAPABILITY, *PSTOR_CRYPTO_CAPABILITY;