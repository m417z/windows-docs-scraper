DXGKCB_WRITE_DEVICE_SPACE DxgkcbWriteDeviceSpace;

NTSTATUS DxgkcbWriteDeviceSpace(
  [in]  HANDLE DeviceHandle,
  [in]  ULONG DataType,
  [in]  PVOID Buffer,
  [in]  ULONG Offset,
  [in]  ULONG Length,
  [out] PULONG BytesWritten
)
{...}