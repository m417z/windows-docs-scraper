FN_VMB_PACKET_SEND_WITH_EXTERNAL_MDL FnVmbPacketSendWithExternalMdl;

NTSTATUS FnVmbPacketSendWithExternalMdl(
  __drv_aliasesMem VMBPACKET PacketObject,
  PVOID Buffer,
  UINT32 BufferLength,
  PMDL ExternalDataMdl,
  UINT32 MdlOffset,
  UINT32 MdlLength,
  UINT32 Flags
)
{...}