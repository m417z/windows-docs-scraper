FN_VMB_PACKET_SEND FnVmbPacketSend;

NTSTATUS FnVmbPacketSend(
  __drv_aliasesMem VMBPACKET PacketObject,
  PVOID Buffer,
  UINT32 BufferLength,
  PMDL ExternalDataMdl,
  UINT32 Flags
)
{...}