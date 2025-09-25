PCAM_PROCESS_RAW_FRAME_ROUTINE PcamProcessRawFrameRoutine;

NTSTATUS PcamProcessRawFrameRoutine(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PVOID FrameContext,
  PVOID FrameBuffer,
  ULONG FrameLength,
  PVOID RawFrameBuffer,
  ULONG RawFrameLength,
  ULONG NumberOfPackets,
  PULONG BytesReturned
)
{...}