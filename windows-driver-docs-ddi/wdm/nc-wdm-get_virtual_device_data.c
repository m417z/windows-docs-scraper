GET_VIRTUAL_DEVICE_DATA GetVirtualDeviceData;

ULONG GetVirtualDeviceData(
  [in, out] PVOID Context,
  [in]      USHORT VirtualFunction,
  [out]     PVOID Buffer,
  [in]      ULONG Offset,
  [in]      ULONG Length
)
{...}