# NdisAdvanceNetBufferDataStart function

## Description

Call the
**NdisAdvanceNetBufferDataStart** function to release the
*used data space* that was added with the
[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart) function.

## Parameters

### `NetBuffer` [in]

A pointer to a previously allocated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

### `DataOffsetDelta` [in]

The amount of
*used data space* to release. NDIS adjusts the value of the
**DataOffset** member of the NET_BUFFER structure accordingly.

### `FreeMdl` [in]

A BOOLEAN value that, if **TRUE**, requests NDIS to free any MDLs that become unused in the advance
operation. If
*FreeMdl* is **FALSE**, NDIS retains unused MDLs for use in subsequent retreat operations.

### `FreeMdlHandler` [in, optional]

An optional entry point for an
[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl) function. If the caller
specifies an entry point for the
*NetFreeMdl* function, NDIS calls
*NetFreeMdl* to free an MDL and memory.

## Remarks

If NDIS allocated memory to satisfy a corresponding call to the
[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart) function, then
**NdisAdvanceNetBufferDataStart** frees the memory that
**NdisRetreatNetBufferDataStart** allocated. Otherwise, the memory remains in the MDL and only the
value of the
**DataOffset** member of the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure is modified.

NDIS calls the
[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl) function specified at
*FreeMdl* if
**NdisAdvanceNetBufferDataStart** must free memory. NDIS calls
*NetFreeMdl* only to free the MDLs and memory that the driver allocated in the
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function.

When protocol drivers call
**NdisAdvanceNetBufferDataStart** on the receive path to access the various transport headers, the MDL
chain should not be modified and
*FreeMdl* is **FALSE**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)

[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl)

[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl)