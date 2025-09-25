DXGKCB_QUERYVIDPNINTERFACE DxgkcbQueryvidpninterface;

NTSTATUS DxgkcbQueryvidpninterface(
  [in]  IN_CONST_D3DKMDT_HVIDPN hVidPn,
  [in]  IN_CONST_DXGK_VIDPN_INTERFACE_VERSION VidPnInterfaceVersion,
  [out] DEREF_OUT_CONST_PPDXGK_VIDPN_INTERFACE ppVidPnInterface
)
{...}