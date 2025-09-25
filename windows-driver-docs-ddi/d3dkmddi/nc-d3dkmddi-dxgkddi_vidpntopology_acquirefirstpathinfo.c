DXGKDDI_VIDPNTOPOLOGY_ACQUIREFIRSTPATHINFO DxgkddiVidpntopologyAcquirefirstpathinfo;

NTSTATUS DxgkddiVidpntopologyAcquirefirstpathinfo(
  [in]  IN_CONST_D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology,
  [out] DEREF_OUT_CONST_PPD3DKMDT_VIDPN_PRESENT_PATH ppFirstVidPnPresentPathInfo
)
{...}