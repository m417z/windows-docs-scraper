# NetTxQueueGetRingCollection function

## Description

The **NetTxQueueGetRingCollection** function retrieves the [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure for a transmit (Tx) queue.

## Parameters

### `PacketQueue` [_In_]

A pointer to a NetAdapterCx-allocated **NETPACKETQUEUE** structure. The client driver receives a pointer to this **NETPACKETQUEUE** structure in its *[EVT_NET_ADAPTER_CREATE_TXQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)* callback function.

## Return value

Returns a pointer to the queue's [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure.

## Remarks

Use the [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure returned by this function to access a transmit queue's net rings.

## See also