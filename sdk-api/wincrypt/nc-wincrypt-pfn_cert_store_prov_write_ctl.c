PFN_CERT_STORE_PROV_WRITE_CTL PfnCertStoreProvWriteCtl;

BOOL PfnCertStoreProvWriteCtl(
  [in] HCERTSTOREPROV hStoreProv,
  [in] PCCTL_CONTEXT pCtlContext,
  [in] DWORD dwFlags
)
{...}