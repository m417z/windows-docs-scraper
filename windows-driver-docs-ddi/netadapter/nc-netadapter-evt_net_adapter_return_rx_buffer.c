EVT_NET_ADAPTER_RETURN_RX_BUFFER EvtNetAdapterReturnRxBuffer;

void EvtNetAdapterReturnRxBuffer(
  [_In_] NETADAPTER Adapter,
  [_In_] NET_FRAGMENT_RETURN_CONTEXT_HANDLE RxReturnContext
)
{...}