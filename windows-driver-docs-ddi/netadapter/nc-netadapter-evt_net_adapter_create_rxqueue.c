EVT_NET_ADAPTER_CREATE_RXQUEUE EvtNetAdapterCreateRxqueue;

NTSTATUS EvtNetAdapterCreateRxqueue(
  [_In_]    NETADAPTER Adapter,
  [_Inout_] NETRXQUEUE_INIT *RxQueueInit
)
{...}