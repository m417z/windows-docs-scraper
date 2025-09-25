PFN_CERT_STORE_PROV_READ_CTL PfnCertStoreProvReadCtl;

BOOL PfnCertStoreProvReadCtl(
  [in]  HCERTSTOREPROV hStoreProv,
  [in]  PCCTL_CONTEXT pStoreCtlContext,
  [in]  DWORD dwFlags,
  [out] PCCTL_CONTEXT *ppProvCtlContext
)
{...}