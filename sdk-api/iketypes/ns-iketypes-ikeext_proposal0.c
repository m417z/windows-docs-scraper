typedef struct IKEEXT_PROPOSAL0_ {
  IKEEXT_CIPHER_ALGORITHM0    cipherAlgorithm;
  IKEEXT_INTEGRITY_ALGORITHM0 integrityAlgorithm;
  UINT32                      maxLifetimeSeconds;
  IKEEXT_DH_GROUP             dhGroup;
  UINT32                      quickModeLimit;
} IKEEXT_PROPOSAL0;