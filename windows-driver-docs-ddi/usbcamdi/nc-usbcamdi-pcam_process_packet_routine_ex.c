PCAM_PROCESS_PACKET_ROUTINE_EX PcamProcessPacketRoutineEx;

ULONG PcamProcessPacketRoutineEx(
  PDEVICE_OBJECT BusDeviceObject,
  PVOID DeviceContext,
  PVOID CurrentFrameContext,
  PUSBD_ISO_PACKET_DESCRIPTOR SyncPacket,
  PVOID SyncBuffer,
  PUSBD_ISO_PACKET_DESCRIPTOR DataPacket,
  PVOID DataBuffer,
  PBOOLEAN FrameComplete,
  PULONG PacketFlag,
  PULONG ValidDataOffset
)
{...}