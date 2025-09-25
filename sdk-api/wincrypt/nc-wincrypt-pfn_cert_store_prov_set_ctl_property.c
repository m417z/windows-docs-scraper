PFN_CERT_STORE_PROV_SET_CTL_PROPERTY PfnCertStoreProvSetCtlProperty;

BOOL PfnCertStoreProvSetCtlProperty(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCTL_CONTEXT pCtlContext,
  [in] DWORD dwPropId,
  [in] DWORD dwFlags,
  [in] const void *pvData
)
{...}