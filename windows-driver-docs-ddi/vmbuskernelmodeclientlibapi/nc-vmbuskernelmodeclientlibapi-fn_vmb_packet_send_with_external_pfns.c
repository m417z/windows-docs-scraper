FN_VMB_PACKET_SEND_WITH_EXTERNAL_PFNS FnVmbPacketSendWithExternalPfns;

NTSTATUS FnVmbPacketSendWithExternalPfns(
  __drv_aliasesMem VMBPACKET PacketObject,
  PVOID Buffer,
  UINT32 BufferLength,
  PPFN_NUMBER ExternalDataPfns,
  UINT32 PfnLength,
  UINT32 Flags
)
{...}