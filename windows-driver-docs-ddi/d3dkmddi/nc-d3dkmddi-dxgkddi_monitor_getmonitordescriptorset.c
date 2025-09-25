DXGKDDI_MONITOR_GETMONITORDESCRIPTORSET DxgkddiMonitorGetmonitordescriptorset;

NTSTATUS DxgkddiMonitorGetmonitordescriptorset(
  [in]  IN_CONST_D3DKMDT_ADAPTER hAdapter,
  [in]  IN_CONST_D3DDDI_VIDEO_PRESENT_TARGET_ID VideoPresentTargetId,
  [out] OUT_PD3DKMDT_HMONITORDESCRIPTORSET phMonitorDescriptorSet,
  [out] DEREF_OUT_CONST_PPDXGK_MONITORDESCRIPTORSET_INTERFACE ppMonitorDescriptorSetInterface
)
{...}