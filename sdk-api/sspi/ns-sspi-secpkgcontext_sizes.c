typedef struct _SecPkgContext_Sizes {
  unsigned long cbMaxToken;
  unsigned long cbMaxSignature;
  unsigned long cbBlockSize;
  unsigned long cbSecurityTrailer;
} SecPkgContext_Sizes, *PSecPkgContext_Sizes;