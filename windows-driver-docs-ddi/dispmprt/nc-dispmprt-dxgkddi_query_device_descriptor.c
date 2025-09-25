DXGKDDI_QUERY_DEVICE_DESCRIPTOR DxgkddiQueryDeviceDescriptor;

NTSTATUS DxgkddiQueryDeviceDescriptor(
  [in]      IN_CONST_PVOID MiniportDeviceContext,
  [in]      IN_ULONG ChildUid,
  [in, out] INOUT_PDXGK_DEVICE_DESCRIPTOR DeviceDescriptor
)
{...}