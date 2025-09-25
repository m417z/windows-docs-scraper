typedef struct _SecPkgContext_SupportedSignatures {
  WORD cSignatureAndHashAlgorithms;
  WORD *pSignatureAndHashAlgorithms;
} SecPkgContext_SupportedSignatures, *PSecPkgContext_SupportedSignatures;