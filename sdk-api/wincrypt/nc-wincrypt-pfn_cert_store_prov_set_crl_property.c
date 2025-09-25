PFN_CERT_STORE_PROV_SET_CRL_PROPERTY PfnCertStoreProvSetCrlProperty;

BOOL PfnCertStoreProvSetCrlProperty(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCRL_CONTEXT pCrlContext,
  [in] DWORD dwPropId,
  [in] DWORD dwFlags,
  [in] const void *pvData
)
{...}