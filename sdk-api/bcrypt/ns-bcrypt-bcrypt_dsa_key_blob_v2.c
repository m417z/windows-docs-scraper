typedef struct _BCRYPT_DSA_KEY_BLOB_V2 {
  ULONG               dwMagic;
  ULONG               cbKey;
  HASHALGORITHM_ENUM  hashAlgorithm;
  DSAFIPSVERSION_ENUM standardVersion;
  ULONG               cbSeedLength;
  ULONG               cbGroupSize;
  UCHAR               Count[4];
} BCRYPT_DSA_KEY_BLOB_V2, *PBCRYPT_DSA_KEY_BLOB_V2;