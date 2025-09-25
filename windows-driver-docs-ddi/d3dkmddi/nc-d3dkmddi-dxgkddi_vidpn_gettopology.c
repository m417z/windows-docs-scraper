DXGKDDI_VIDPN_GETTOPOLOGY DxgkddiVidpnGettopology;

NTSTATUS DxgkddiVidpnGettopology(
  [in]  IN_CONST_D3DKMDT_HVIDPN hVidPn,
  [out] OUT_PD3DKMDT_HVIDPNTOPOLOGY phVidPnTopology,
  [out] DEREF_OUT_CONST_PPDXGK_VIDPNTOPOLOGY_INTERFACE ppVidPnTopologyInterface
)
{...}