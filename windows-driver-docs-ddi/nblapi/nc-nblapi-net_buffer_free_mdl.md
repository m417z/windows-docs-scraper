## Description

The
*NetFreeMdl* function frees an MDL that was previously allocated by the
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function.

## Parameters

### `Mdl` [in]

A pointer to the MDL that is to be freed.

## Remarks

If the NDIS driver specifies an entry point for the
*NetFreeMdl* function at the
*FreeMdl* parameter of the
[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function, NDIS calls
*NetFreeMdl* to free an MDL and memory.

*NetFreeMdl* frees the MDL and memory that were allocated by the
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function.

When
*NetFreeMdl* frees the memory, it should use the same memory management mechanism that was used in
*NetAllocateMdl* to allocate the memory.

NDIS calls
*NetFreeMdl* at IRQL <= DISPATCH_LEVEL.

## See also

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl)