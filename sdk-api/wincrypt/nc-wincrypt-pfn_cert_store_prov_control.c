PFN_CERT_STORE_PROV_CONTROL PfnCertStoreProvControl;

BOOL PfnCertStoreProvControl(
  [in, out]      HCERTSTOREPROV hStoreProv,
  [in]           DWORD dwFlags,
  [in]           DWORD dwCtrlType,
  [in, optional] void const *pvCtrlPara
)
{...}