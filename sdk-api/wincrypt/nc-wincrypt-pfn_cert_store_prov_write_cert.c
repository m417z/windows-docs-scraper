PFN_CERT_STORE_PROV_WRITE_CERT PfnCertStoreProvWriteCert;

BOOL PfnCertStoreProvWriteCert(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCERT_CONTEXT pCertContext,
  [in] DWORD dwFlags
)
{...}