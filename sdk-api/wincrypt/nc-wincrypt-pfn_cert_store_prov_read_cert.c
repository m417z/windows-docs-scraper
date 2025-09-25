PFN_CERT_STORE_PROV_READ_CERT PfnCertStoreProvReadCert;

BOOL PfnCertStoreProvReadCert(
  [in]  HCERTSTOREPROV hStoreProv,
  [in]  PCCERT_CONTEXT pStoreCertContext,
  [in]  DWORD dwFlags,
  [out] PCCERT_CONTEXT *ppProvCertContext
)
{...}