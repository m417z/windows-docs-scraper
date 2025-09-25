# NetRxQueueGetRingCollection function

## Description

The **NetRxQueueGetRingCollection** function retrieves the [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure for a receive (Rx) queue.

## Parameters

### `PacketQueue` [_In_]

A **NETPACKETQUEUE** structure. The client driver receives a pointer to this **NETPACKETQUEUE** structure in its *[EVT_NET_ADAPTER_CREATE_RXQUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue)* callback function.

## Return value

Returns a pointer to the queue's [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure.

## Remarks

Use the [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure returned by this function to access a receive queue's net rings.

## See also