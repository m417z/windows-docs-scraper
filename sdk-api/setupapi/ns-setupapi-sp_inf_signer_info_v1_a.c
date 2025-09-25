typedef struct _SP_INF_SIGNER_INFO_V1_A {
  DWORD cbSize;
  CHAR  CatalogFile[MAX_PATH];
  CHAR  DigitalSigner[MAX_PATH];
  CHAR  DigitalSignerVersion[MAX_PATH];
} SP_INF_SIGNER_INFO_V1_A, *PSP_INF_SIGNER_INFO_V1_A;