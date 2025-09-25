FN_VMB_CHANNEL_ALLOCATE FnVmbChannelAllocate;

NTSTATUS FnVmbChannelAllocate(
  PDEVICE_OBJECT ParentDeviceObject,
  BOOLEAN IsServer,
  VMBCHANNEL *Channel
)
{...}