typedef struct _SecPkgContext_KeyInfoA {
  SEC_CHAR      *sSignatureAlgorithmName;
  SEC_CHAR      *sEncryptAlgorithmName;
  unsigned long KeySize;
  unsigned long SignatureAlgorithm;
  unsigned long EncryptAlgorithm;
} SecPkgContext_KeyInfoA, *PSecPkgContext_KeyInfoA;