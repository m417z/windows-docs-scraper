# NdisRetreatNetBufferDataStart function

## Description

Call the
**NdisRetreatNetBufferDataStart** function to access more
*used data space* in the MDL chain of a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Parameters

### `NetBuffer` [in]

A pointer to a previously allocated NET_BUFFER structure.

### `DataOffsetDelta` [in]

The amount of
*used data space* to add. NDIS adjusts the
**DataOffset** member of the NET_BUFFER structure accordingly. If there is not enough
*unused data space* to satisfy the request, NDIS allocates additional memory.

### `DataBackFill` [in]

If NDIS must allocate memory, this parameter specifies the amount of data space, in addition to
the value of the
*DataOffsetDelta* parameter, to allocate.

### `AllocateMdlHandler` [in, optional]

An optional entry point for an
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function. If the caller
specifies an entry point for the
*NetAllocateMdl* function, NDIS calls
*NetAllocateMdl* to allocate an MDL and memory.

## Return value

**NdisRetreatNetBufferDataStart** returns one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisRetreatNetBufferDataStart** successfully allocated *used data space* either by using the *unused data space* or by allocating new storage. |
| **NDIS_STATUS_RESOURCES** | **NdisRetreatNetBufferDataStart** failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | **NdisRetreatNetBufferDataStart** failed for reasons other than insufficient resources. |

## Remarks

**NdisRetreatNetBufferDataStart** attempts to satisfy the request by reducing the value of the
**DataOffset** member of the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

If there isn't enough
*unused data space*, this function allocates a new buffer and an MDL to describe the new buffer and
chains the new MDL to the beginning of the MDL chain. NDIS calls the
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function specified at
*AllocateMdl* to allocate the MDL and memory. The
*NetAllocateMdl* function can use any allocation method that meets the
driver's design requirements.

Call the
[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function to release the
*used data space* that was added with
**NdisRetreatNetBufferDataStart**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl)