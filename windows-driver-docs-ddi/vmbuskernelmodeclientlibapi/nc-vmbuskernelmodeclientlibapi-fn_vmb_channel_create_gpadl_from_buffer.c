FN_VMB_CHANNEL_CREATE_GPADL_FROM_BUFFER FnVmbChannelCreateGpadlFromBuffer;

NTSTATUS FnVmbChannelCreateGpadlFromBuffer(
  VMBCHANNEL Channel,
  UINT32 Flags,
  PVOID Buffer,
  UINT32 ByteCount,
  PUINT32 GpadlHandle
)
{...}