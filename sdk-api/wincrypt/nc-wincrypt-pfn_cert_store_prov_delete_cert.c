PFN_CERT_STORE_PROV_DELETE_CERT PfnCertStoreProvDeleteCert;

BOOL PfnCertStoreProvDeleteCert(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCERT_CONTEXT pCertContext,
  [in] DWORD dwFlags
)
{...}