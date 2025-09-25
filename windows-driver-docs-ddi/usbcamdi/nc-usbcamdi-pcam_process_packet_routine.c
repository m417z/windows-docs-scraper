PCAM_PROCESS_PACKET_ROUTINE PcamProcessPacketRoutine;

ULONG PcamProcessPacketRoutine(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PVOID CurrentFrameContext,
  PUSBD_ISO_PACKET_DESCRIPTOR SyncPacket,
  PVOID SyncBuffer,
  PUSBD_ISO_PACKET_DESCRIPTOR DataPacket,
  PVOID DataBuffer,
  PBOOLEAN FrameComplete,
  PBOOLEAN NextFrameIsStill
)
{...}