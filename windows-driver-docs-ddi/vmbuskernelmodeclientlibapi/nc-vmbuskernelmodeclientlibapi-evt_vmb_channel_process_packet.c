EVT_VMB_CHANNEL_PROCESS_PACKET EvtVmbChannelProcessPacket;

VOID EvtVmbChannelProcessPacket(
  [in] VMBCHANNEL Channel,
  [in] VMBPACKETCOMPLETION Packet,
  [in] PVOID Buffer,
  [in] UINT32 BufferLength,
  [in] UINT32 Flags
)
{...}