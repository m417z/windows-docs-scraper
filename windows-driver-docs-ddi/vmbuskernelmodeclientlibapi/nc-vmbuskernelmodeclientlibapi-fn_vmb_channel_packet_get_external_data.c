FN_VMB_CHANNEL_PACKET_GET_EXTERNAL_DATA FnVmbChannelPacketGetExternalData;

NTSTATUS FnVmbChannelPacketGetExternalData(
  VMBPACKETCOMPLETION PacketCompletionContext,
  UINT32 Flags,
  PMDL *Mdl
)
{...}