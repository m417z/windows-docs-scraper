FN_VMB_CHANNEL_CREATE_GPADL_FROM_MDL FnVmbChannelCreateGpadlFromMdl;

NTSTATUS FnVmbChannelCreateGpadlFromMdl(
  VMBCHANNEL Channel,
  UINT32 Flags,
  PMDL Mdl,
  UINT32 StartOffsetWithinMdl,
  UINT32 DataLengthWithinMdl,
  PUINT32 GpadlHandle
)
{...}