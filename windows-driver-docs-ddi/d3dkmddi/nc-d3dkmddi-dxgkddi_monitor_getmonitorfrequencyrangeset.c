DXGKDDI_MONITOR_GETMONITORFREQUENCYRANGESET DxgkddiMonitorGetmonitorfrequencyrangeset;

NTSTATUS DxgkddiMonitorGetmonitorfrequencyrangeset(
  [in]  IN_CONST_D3DKMDT_ADAPTER hAdapter,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VideoPresentTargetId,
  [out] OUT_PD3DKMDT_HMONITORFREQUENCYRANGESET phMonitorFrequencyRangeSet,
  [out] DEREF_OUT_CONST_PPDXGK_MONITORFREQUENCYRANGESET_INTERFACE ppMonitorFrequencyRangeSetInterface
)
{...}