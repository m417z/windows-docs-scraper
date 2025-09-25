SRIOV_GET_DEVICE_LOCATION SriovGetDeviceLocation;

VOID SriovGetDeviceLocation(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [out] PUINT16 SegmentNumber,
  [out] PUINT8 BusNumber,
  [out] PUINT8 FunctionNumber
)
{...}