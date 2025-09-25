DXGKCB_READ_DEVICE_SPACE DxgkcbReadDeviceSpace;

NTSTATUS DxgkcbReadDeviceSpace(
  [in]  HANDLE DeviceHandle,
  [in]  ULONG DataType,
  [in]  PVOID Buffer,
  [in]  ULONG Offset,
  [in]  ULONG Length,
  [out] PULONG BytesRead
)
{...}