typedef struct _SP_INF_SIGNER_INFO_V2_A {
  DWORD cbSize;
  CHAR  CatalogFile[MAX_PATH];
  CHAR  DigitalSigner[MAX_PATH];
  CHAR  DigitalSignerVersion[MAX_PATH];
  DWORD SignerScore;
} SP_INF_SIGNER_INFO_V2_A, *PSP_INF_SIGNER_INFO_V2_A;