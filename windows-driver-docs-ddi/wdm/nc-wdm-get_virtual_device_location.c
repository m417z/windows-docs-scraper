GET_VIRTUAL_DEVICE_LOCATION GetVirtualDeviceLocation;

NTSTATUS GetVirtualDeviceLocation(
  [in, out] PVOID Context,
  [in]      USHORT VirtualFunction,
  [out]     PUINT16 SegmentNumber,
  [out]     PUINT8 BusNumber,
  [out]     PUINT8 FunctionNumber
)
{...}