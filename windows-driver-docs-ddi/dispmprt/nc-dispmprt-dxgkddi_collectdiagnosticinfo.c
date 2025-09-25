DXGKDDI_COLLECTDIAGNOSTICINFO DxgkddiCollectdiagnosticinfo;

NTSTATUS DxgkddiCollectdiagnosticinfo(
  [in]      IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject,
  [in, out] INOUT_PDXGKARG_COLLECTDIAGNOSTICINFO pCollectDiagnosticInfo
)
{...}