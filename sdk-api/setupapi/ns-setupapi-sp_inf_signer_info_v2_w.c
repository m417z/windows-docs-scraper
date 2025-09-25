typedef struct _SP_INF_SIGNER_INFO_V2_W {
  DWORD cbSize;
  WCHAR CatalogFile[MAX_PATH];
  WCHAR DigitalSigner[MAX_PATH];
  WCHAR DigitalSignerVersion[MAX_PATH];
  DWORD SignerScore;
} SP_INF_SIGNER_INFO_V2_W, *PSP_INF_SIGNER_INFO_V2_W;