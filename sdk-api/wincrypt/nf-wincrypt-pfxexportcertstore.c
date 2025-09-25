BOOL PFXExportCertStore(
  [in]      HCERTSTORE      hStore,
  [in, out] CRYPT_DATA_BLOB *pPFX,
  [in]      LPCWSTR         szPassword,
  [in]      DWORD           dwFlags
);