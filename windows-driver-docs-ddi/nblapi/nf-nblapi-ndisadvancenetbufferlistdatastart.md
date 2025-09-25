# NdisAdvanceNetBufferListDataStart function

## Description

Call the
**NdisAdvanceNetBufferListDataStart** function to release data space that was claimed in previous calls
to the
[NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart) function.

## Parameters

### `NetBufferList` [in]

A pointer to a previously allocated
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

### `DataOffsetDelta` [in]

The amount of
*used data space* to release.

### `FreeMdl` [in]

If **TRUE** and NDIS allocated memory to satisfy the corresponding
**NdisRetreatNetBufferListDataStart** call, this function frees the memory that was allocated and the
associated MDL.

### `FreeMdlMdlHandler`

An optional entry point for an
[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl) function. If the caller
specifies an entry point for the
*NetFreeMdl* function, NDIS calls
*NetFreeMdl* to free an MDL and memory.

## Remarks

**NdisAdvanceNetBufferListDataStart** releases
*used data space* for all the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures in a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. If
*FreeMdl* is **TRUE** and
[NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart) allocated memory to satisfy the corresponding allocation request,
**NdisAdvanceNetBufferListDataStart** frees the allocated memory. Calling this function is equivalent
to calling
[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) for every NET_BUFFER structure on the NET_BUFFER_LIST structure.
However, calling
**NdisAdvanceNetBufferListDataStart** is more efficient.

When protocol drivers call
**NdisAdvanceNetBufferListDataStart** on the receive path to access the various transport headers, the
MDL chain should not be modified and
*FreeMdl* is **FALSE**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart)

[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl)

[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl)