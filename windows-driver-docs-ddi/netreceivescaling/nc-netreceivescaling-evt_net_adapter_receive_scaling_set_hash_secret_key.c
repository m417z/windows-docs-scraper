EVT_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY EvtNetAdapterReceiveScalingSetHashSecretKey;

NTSTATUS EvtNetAdapterReceiveScalingSetHashSecretKey(
  [_In_] NETADAPTER Adapter,
  [_In_] const NET_ADAPTER_RECEIVE_SCALING_HASH_SECRET_KEY *HashSecretKey
)
{...}