DXGKDDI_VIDPNTARGETMODESET_ACQUIRENEXTMODEINFO DxgkddiVidpntargetmodesetAcquirenextmodeinfo;

NTSTATUS DxgkddiVidpntargetmodesetAcquirenextmodeinfo(
  [in]  IN_CONST_D3DKMDT_HVIDPNTARGETMODESET hVidPnTargetModeSet,
  [in]  IN_CONST_PD3DKMDT_VIDPN_TARGET_MODE_CONST pVidPnTargetModeInfo,
  [out] DEREF_OUT_CONST_PPD3DKMDT_VIDPN_TARGET_MODE ppNextVidPnTargetModeInfo
)
{...}