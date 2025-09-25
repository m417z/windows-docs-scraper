FN_VMB_CHANNEL_SEND_SYNCHRONOUS_REQUEST FnVmbChannelSendSynchronousRequest;

NTSTATUS FnVmbChannelSendSynchronousRequest(
  VMBCHANNEL Channel,
  PVOID Buffer,
  UINT32 BufferSize,
  PMDL ExternalDataMdl,
  UINT32 Flags,
  PVOID CompletionBuffer,
  PUINT32 CompletionBufferSize,
  PLARGE_INTEGER Timeout
)
{...}