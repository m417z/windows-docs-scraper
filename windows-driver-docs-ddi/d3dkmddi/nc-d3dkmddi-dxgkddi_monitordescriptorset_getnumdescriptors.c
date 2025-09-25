DXGKDDI_MONITORDESCRIPTORSET_GETNUMDESCRIPTORS DxgkddiMonitordescriptorsetGetnumdescriptors;

NTSTATUS DxgkddiMonitordescriptorsetGetnumdescriptors(
  [in]  IN_CONST_D3DKMDT_HMONITORDESCRIPTORSET hMonitorDescriptorSet,
  [out] OUT_PSIZE_T_CONST pNumMonitorDescriptors
)
{...}