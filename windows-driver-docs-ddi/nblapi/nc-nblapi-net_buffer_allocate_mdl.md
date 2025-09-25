## Description

The
*NetAllocateMdl* function allocates an MDL with an associated memory block of a specified size.

## Parameters

### `BufferSize` [in]

The size of the memory block, in bytes. When calling
*NetAllocateMdl*, NDIS passes in the requested size.

## Return value

*NetAllocateMdl* returns a pointer to the allocated MDL. If the allocation fails, the return value
is **NULL**.

## Remarks

If the NDIS driver specifies an entry point for the
*NetAllocateMdl* function at the
*AllocateMdl* parameter of the
[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart) function, NDIS calls
*NetAllocateMdl* to allocate an MDL and memory.

NDIS specifies the size of the associated memory block at
*BufferSize* .

*NetAllocateMdl* can use any allocation method that meets the driver's design requirements. When NDIS
calls the
[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl) function to free the memory, the
NDIS driver should free the memory by using the same memory management mechanism that it used to allocate
the memory.

NDIS calls
*NetAllocateMdl* at IRQL <= DISPATCH_LEVEL.

## See also

[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)

[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl)