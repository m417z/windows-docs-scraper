FN_VMB_CLIENT_CHANNEL_INIT_SET_TARGET_PNP FnVmbClientChannelInitSetTargetPnp;

NTSTATUS FnVmbClientChannelInitSetTargetPnp(
  VMBCHANNEL Channel,
  LPCGUID InterfaceType,
  LPCGUID InterfaceInstance,
  PFN_VMB_CHANNEL_PNP_FAILURE PnpFailureCallback
)
{...}