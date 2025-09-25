SET_VIRTUAL_DEVICE_DATA SetVirtualDeviceData;

ULONG SetVirtualDeviceData(
  [in, out] PVOID Context,
  [in]      USHORT VirtualFunction,
  [in]      PVOID Buffer,
  [in]      ULONG Offset,
  [in]      ULONG Length
)
{...}