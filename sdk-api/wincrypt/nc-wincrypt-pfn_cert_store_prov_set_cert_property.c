PFN_CERT_STORE_PROV_SET_CERT_PROPERTY PfnCertStoreProvSetCertProperty;

BOOL PfnCertStoreProvSetCertProperty(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCERT_CONTEXT pCertContext,
  [in] DWORD dwPropId,
  [in] DWORD dwFlags,
  [in] const void *pvData
)
{...}