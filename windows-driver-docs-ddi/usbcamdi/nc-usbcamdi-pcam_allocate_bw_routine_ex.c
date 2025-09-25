PCAM_ALLOCATE_BW_ROUTINE_EX PcamAllocateBwRoutineEx;

NTSTATUS PcamAllocateBwRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PULONG RawFrameLength,
  PVOID Format,
  ULONG StreamNumber
)
{...}