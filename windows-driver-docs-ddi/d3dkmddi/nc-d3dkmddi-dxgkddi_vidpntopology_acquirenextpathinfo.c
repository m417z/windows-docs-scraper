DXGKDDI_VIDPNTOPOLOGY_ACQUIRENEXTPATHINFO DxgkddiVidpntopologyAcquirenextpathinfo;

NTSTATUS DxgkddiVidpntopologyAcquirenextpathinfo(
  [in]  IN_CONST_D3DKMDT_HVIDPNTOPOLOGY hVidPnTopology,
  [in]  IN_CONST_PD3DKMDT_VIDPN_PRESENT_PATH_CONST pVidPnPresentPathInfo,
  [out] DEREF_OUT_CONST_PPD3DKMDT_VIDPN_PRESENT_PATH ppNextVidPnPresentPathInfo
)
{...}