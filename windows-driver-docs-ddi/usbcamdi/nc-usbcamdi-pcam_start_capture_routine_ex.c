PCAM_START_CAPTURE_ROUTINE_EX PcamStartCaptureRoutineEx;

NTSTATUS PcamStartCaptureRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  ULONG StreamNumber
)
{...}