# NdisFreePacketPool

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

This function releases a handle to a block of packet pool that was allocated with the **NdisAllocatePacketPool** function.

## Parameters

### `PoolHandle`

Handle returned when the driver called **NdisAllocatePacketPool**. The pool handle is no longer valid after this function returns.

## Remarks

This function frees the storage for the packet pool. Before calling this function, the driver must call the **NdisFreePacket** function as many times as necessary to release all packet descriptors that it has allocated with the **NdisAllocatePacket** function, but not yet freed.

The driver must also release any spin lock that it is holding before calling this function.

A driver that calls this function runs at IRQL \<= DISPATCH\_LEVEL.

| Runs on | Versions | Defined in | Include | Link to |
| --- | --- | --- | --- | --- |
| Windows CE OS | 2.0 and later | Ndis.h |  |  |

> **Note** This API is part of the complete Windows CE OS package as provided by Microsoft. The functionality of a particular platform is determined by the original equipment manufacturer (OEM) and some devices may not support this API.

## See also

- [NdisAllocatePacket](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550774(v=vs.85))
- [NdisAllocatePacketPool](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550780(v=vs.85))
- [NdisFreePacket](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff551993(v=vs.85))
- [NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)