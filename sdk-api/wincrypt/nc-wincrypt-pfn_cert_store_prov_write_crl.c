PFN_CERT_STORE_PROV_WRITE_CRL PfnCertStoreProvWriteCrl;

BOOL PfnCertStoreProvWriteCrl(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCRL_CONTEXT pCrlContext,
  [in] DWORD dwFlags
)
{...}