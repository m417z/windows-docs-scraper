typedef struct _BCRYPT_DSA_PARAMETER_HEADER_V2 {
  ULONG               cbLength;
  ULONG               dwMagic;
  ULONG               cbKeyLength;
  HASHALGORITHM_ENUM  hashAlgorithm;
  DSAFIPSVERSION_ENUM standardVersion;
  ULONG               cbSeedLength;
  ULONG               cbGroupSize;
  UCHAR               Count[4];
} BCRYPT_DSA_PARAMETER_HEADER_V2;