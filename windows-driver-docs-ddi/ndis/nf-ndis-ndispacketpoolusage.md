# NdisPacketPoolUsage (Windows CE 5.0)

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

This function returns the number of packet descriptors currently allocated from a packet pool.

## Parameters

### `PoolHandle` [in]

Specifies a handle returned by [NdisAllocatePacketPool](https://learn.microsoft.com/previous-versions/windows/embedded/aa447908(v=msdn.10)) or [NdisAllocatePacketPoolEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatepacketpoolex).

## Return value

Returns the number of packet descriptors currently allocated from the given packet pool.

## Remarks

Before allocating packet descriptors for a send or receive indication, an NDIS driver can call **NdisPacketPoolUsage** to determine whether it has enough spare packet descriptors available for the send/receive, particularly if the driver has allocated more than one packet pool.

An NDIS driver also can call this function to be sure that all descriptors have been returned to the given packet pool before it calls [NdisFreePacketPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreepacketpool).

**OS Versions:** Windows CE .NET 4.0 and later.

## See also

- [NdisAllocatePacket](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550774(v=vs.85))
- [NdisAllocatePacketPool](https://learn.microsoft.com/previous-versions/windows/embedded/aa447908(v=msdn.10))
- [NdisAllocatePacketPoolEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatepacketpoolex)
- [NdisDprAllocatePacket](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff551932(v=vs.85))
- [NdisDprAllocatePacketNonInterlocked](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff551937(v=vs.85))
- [NdisFreePacketPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreepacketpool)
- [NdisPacketSize](https://learn.microsoft.com/previous-versions/windows/embedded/aa448321(v=msdn.10))