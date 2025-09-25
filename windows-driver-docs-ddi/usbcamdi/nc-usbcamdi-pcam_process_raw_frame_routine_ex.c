PCAM_PROCESS_RAW_FRAME_ROUTINE_EX PcamProcessRawFrameRoutineEx;

NTSTATUS PcamProcessRawFrameRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PVOID FrameContext,
  PVOID FrameBuffer,
  ULONG FrameLength,
  PVOID RawFrameBuffer,
  ULONG RawFrameLength,
  ULONG NumberOfPackets,
  PULONG BytesReturned,
  ULONG ActualRawFrameLength,
  ULONG StreamNumber
)
{...}