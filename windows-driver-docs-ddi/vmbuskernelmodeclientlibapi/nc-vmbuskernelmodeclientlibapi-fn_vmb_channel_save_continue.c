FN_VMB_CHANNEL_SAVE_CONTINUE FnVmbChannelSaveContinue;

NTSTATUS FnVmbChannelSaveContinue(
  VMBCHANNEL Channel,
  PVOID SaveBuffer,
  ULONG SaveBufferSize,
  PULONG BytesFilled,
  PULONG BytesRequired
)
{...}