DXGKDDI_MONITOR_GETADDITIONALMONITORMODESET DxgkddiMonitorGetadditionalmonitormodeset;

NTSTATUS DxgkddiMonitorGetadditionalmonitormodeset(
  [in]  IN_CONST_D3DKMDT_ADAPTER hAdapter,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VideoPresentTargetId,
  [out] OUT_PUINT pNumberModes,
  [out] DEREF_ECOUNT_PPDXGK_TARGETMODE_DETAIL_TIMING ppAdditionalModesSet
)
{...}