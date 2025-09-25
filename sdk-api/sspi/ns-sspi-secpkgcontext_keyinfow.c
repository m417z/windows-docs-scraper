typedef struct _SecPkgContext_KeyInfoW {
  SEC_WCHAR     *sSignatureAlgorithmName;
  SEC_WCHAR     *sEncryptAlgorithmName;
  unsigned long KeySize;
  unsigned long SignatureAlgorithm;
  unsigned long EncryptAlgorithm;
} SecPkgContext_KeyInfoW, *PSecPkgContext_KeyInfoW;