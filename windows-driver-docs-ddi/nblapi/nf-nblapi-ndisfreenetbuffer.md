# NdisFreeNetBuffer function

## Description

Call the
**NdisFreeNetBuffer** function to free a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure that was previously allocated
from a NET_BUFFER structure pool with the
[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer) function.

## Parameters

### `NetBuffer` [in]

A pointer to a NET_BUFFER structure that was allocated by calling
**NdisAllocateNetBuffer**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)