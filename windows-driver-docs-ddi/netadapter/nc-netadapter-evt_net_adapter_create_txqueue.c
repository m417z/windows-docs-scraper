EVT_NET_ADAPTER_CREATE_TXQUEUE EvtNetAdapterCreateTxqueue;

NTSTATUS EvtNetAdapterCreateTxqueue(
  [_In_]    NETADAPTER Adapter,
  [_Inout_] NETTXQUEUE_INIT *TxQueueInit
)
{...}