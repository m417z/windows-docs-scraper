# _NET_RING_COLLECTION structure

## Description

The **NET_RING_COLLECTION** structure describes the collection of net rings that belong to a packet queue.

## Members

### `Rings`

A pointer to an array of [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring) structures.

## Remarks

Call [**NetRxQueueGetRingCollection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuegetringcollection) or [**NetTxQueueGetRingCollection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuegetringcollection) to get a packet queue's ring collection. You can then use this collection structure to retrieve the queue's packet ring and fragment ring. For more information about using net rings, see [Introduction to net rings](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-net-rings).

## See also

[Introduction to net rings](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-net-rings)