DXGKDDI_LINK_DEVICE DxgkddiLinkDevice;

NTSTATUS DxgkddiLinkDevice(
  [in]      IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject,
  [in]      IN_CONST_PVOID MiniportDeviceContext,
  [in, out] INOUT_PLINKED_DEVICE LinkedDevice
)
{...}