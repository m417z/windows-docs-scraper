DXGKDDI_ADD_DEVICE DxgkddiAddDevice;

NTSTATUS DxgkddiAddDevice(
  [in]  IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject,
  [out] OUT_PPVOID MiniportDeviceContext
)
{...}