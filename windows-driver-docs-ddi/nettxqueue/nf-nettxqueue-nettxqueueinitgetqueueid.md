# NetTxQueueInitGetQueueId function

## Description

Retrieves the identifier associated with a transmit queue.

## Parameters

### `NetTxQueueInit` [_In_]

A pointer to a NetAdapterCx-allocated **NETTXQUEUE_INIT** structure. For more information, see the Remarks section.

## Return value

Returns a ULONG that identifies a transmit queue.

## Remarks

The client driver receives a pointer to a **NETTXQUEUE_INIT** structure in its *[EVT_NET_ADAPTER_CREATE_TXQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)* callback function.

Starting with zero, NetAdapterCx assigns a unique identifier value for each queue that it creates. The client driver specifies the number of transmit queues that the network adapter supports in the **MaximumNumberOfQueues** member of the [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) structure, which is initialized and passed to [NetAdapterSetDataPathCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities) when starting a net adapter. Identifier values range from zero to the value of `(((MaxNumber of TxQueues) + (MaxNumber of RxQueues)) - 1)`.

## See also