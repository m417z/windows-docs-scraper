PCAM_STOP_CAPTURE_ROUTINE_EX PcamStopCaptureRoutineEx;

NTSTATUS PcamStopCaptureRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  ULONG StreamNumber
)
{...}