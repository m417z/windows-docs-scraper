EVT_VMB_CHANNEL_RESTORE_PACKET EvtVmbChannelRestorePacket;

NTSTATUS EvtVmbChannelRestorePacket(
  [in] VMBCHANNEL Channel,
  [in] PVOID LibBuf,
  [in] UINT32 LibBufSize,
  [in] PVOID SaveBuf,
  [in] UINT32 SaveBufSize
)
{...}