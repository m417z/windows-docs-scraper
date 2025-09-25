DXGKDDI_VIDPNSOURCEMODESET_ACQUIRENEXTMODEINFO DxgkddiVidpnsourcemodesetAcquirenextmodeinfo;

NTSTATUS DxgkddiVidpnsourcemodesetAcquirenextmodeinfo(
  [in]  IN_CONST_D3DKMDT_HVIDPNSOURCEMODESET hVidPnSourceModeSet,
  [in]  IN_CONST_PD3DKMDT_VIDPN_SOURCE_MODE_CONST pVidPnSourceModeInfo,
  [out] DEREF_OUT_CONST_PPD3DKMDT_VIDPN_SOURCE_MODE ppNextVidPnSourceModeInfo
)
{...}