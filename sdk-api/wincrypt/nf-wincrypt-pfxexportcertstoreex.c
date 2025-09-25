BOOL PFXExportCertStoreEx(
  [in]      HCERTSTORE      hStore,
  [in, out] CRYPT_DATA_BLOB *pPFX,
  [in]      LPCWSTR         szPassword,
  [in]      void            *pvPara,
  [in]      DWORD           dwFlags
);