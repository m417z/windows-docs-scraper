DXGKDDI_MONITOR_ACQUIREMONITORSOURCEMODESET DxgkddiMonitorAcquiremonitorsourcemodeset;

NTSTATUS DxgkddiMonitorAcquiremonitorsourcemodeset(
  [in]  IN_CONST_D3DKMDT_ADAPTER hAdapter,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VideoPresentTargetId,
  [out] OUT_PD3DKMDT_HMONITORSOURCEMODESET phMonitorSourceModeSet,
  [out] DEREF_OUT_CONST_PPDXGK_MONITORSOURCEMODESET_INTERFACE ppMonitorSourceModeSetInterface
)
{...}