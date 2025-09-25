PFN_CERT_STORE_PROV_READ_CRL PfnCertStoreProvReadCrl;

BOOL PfnCertStoreProvReadCrl(
  [in]  HCERTSTOREPROV hStoreProv,
  [in]  PCCRL_CONTEXT pStoreCrlContext,
  [in]  DWORD dwFlags,
  [out] PCCRL_CONTEXT *ppProvCrlContext
)
{...}