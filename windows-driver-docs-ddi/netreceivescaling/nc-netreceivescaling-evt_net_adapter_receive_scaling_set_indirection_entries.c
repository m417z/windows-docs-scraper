EVT_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES EvtNetAdapterReceiveScalingSetIndirectionEntries;

NTSTATUS EvtNetAdapterReceiveScalingSetIndirectionEntries(
  [_In_]    NETADAPTER Adapter,
  [_Inout_] NET_ADAPTER_RECEIVE_SCALING_INDIRECTION_ENTRIES *IndirectionEntries
)
{...}