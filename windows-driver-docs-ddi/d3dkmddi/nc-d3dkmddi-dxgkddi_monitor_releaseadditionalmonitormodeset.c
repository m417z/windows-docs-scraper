DXGKDDI_MONITOR_RELEASEADDITIONALMONITORMODESET DxgkddiMonitorReleaseadditionalmonitormodeset;

NTSTATUS DxgkddiMonitorReleaseadditionalmonitormodeset(
  [in] IN_CONST_D3DKMDT_ADAPTER hAdapter,
  [in] IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VideoPresentTargetId,
  [in] IN_CONST_PDXGK_TARGETMODE_DETAIL_TIMING pAdditionalModesSet
)
{...}