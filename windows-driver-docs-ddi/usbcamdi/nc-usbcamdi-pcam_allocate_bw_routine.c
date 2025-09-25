PCAM_ALLOCATE_BW_ROUTINE PcamAllocateBwRoutine;

NTSTATUS PcamAllocateBwRoutine(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PULONG RawFrameLength,
  PVOID Format
)
{...}