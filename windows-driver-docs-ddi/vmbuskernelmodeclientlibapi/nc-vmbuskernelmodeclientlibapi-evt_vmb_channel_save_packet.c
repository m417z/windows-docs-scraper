EVT_VMB_CHANNEL_SAVE_PACKET EvtVmbChannelSavePacket;

NTSTATUS EvtVmbChannelSavePacket(
  [in]  VMBCHANNEL Channel,
  [in]  VMBPACKET Packet,
  [out] PVOID SaveBuf,
  [in]  UINT32 SaveBufSize,
  [out] PUINT32 BytesNeeded
)
{...}