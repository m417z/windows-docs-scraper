# NetRingCollectionGetPacketRing function

## Description

The **NetRingCollectionGetPacketRing** gets the packet ring for a packet queue.

## Parameters

### `Rings`

A pointer to a [**NET_RING_COLLECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ringcollection/ns-ringcollection-_net_ring_collection) structure that describes this packet queue's net rings.

## Return value

Returns a pointer to the packet [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring) for the packet queue.

## Remarks

Client drivers typically call this function when they need information about a packet ring, such as the number of elements in the ring. For example, during its queue initialization routines a client driver might need to allocate memory for hardware descriptors in a one-to-one ratio to the number of packets in the packet ring.

## See also

[Introduction to net rings](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-net-rings)