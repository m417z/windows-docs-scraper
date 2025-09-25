# NdisAllocateNetBufferMdlAndData function

## Description

NDIS drivers call the
**NdisAllocateNetBufferMdlAndData** function to allocate a NET_BUFFER structure along with the associated
MDL and data.

## Parameters

### `PoolHandle` [in]

A NET_BUFFER structure pool handle that was previously returned from a call to the
**NdisAllocateNetBufferPool** function.

## Return value

**NdisAllocateNetBufferMdlAndData** returns a pointer to the NET_BUFFER structure that NDIS allocated.
If the allocation was unsuccessful, this pointer is **NULL**.

## Remarks

The caller must call the
**NdisAllocateNetBufferPool** function and specify the maximum size of the data buffers. Given this
value, NDIS can preallocate buffers for the caller.

This function allocates a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure, MDL and data in a single
memory buffer. This is useful to achieve high performance when NET_BUFFER structures are frequently
allocated and freed. The caller should not call
[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer) to allocate
NET_BUFFERs out of NET_BUFFER pools which contain data.

NDIS uses the
*PoolHandle* parameter to get a block of memory, and then creates the NET_BUFFER, MDL, and data
buffer.

To free the NET_BUFFER and associated information, call the
[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer) function.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)

[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer)