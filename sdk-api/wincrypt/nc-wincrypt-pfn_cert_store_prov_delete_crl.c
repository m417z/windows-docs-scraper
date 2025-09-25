PFN_CERT_STORE_PROV_DELETE_CRL PfnCertStoreProvDeleteCrl;

BOOL PfnCertStoreProvDeleteCrl(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCRL_CONTEXT pCrlContext,
  [in] DWORD dwFlags
)
{...}