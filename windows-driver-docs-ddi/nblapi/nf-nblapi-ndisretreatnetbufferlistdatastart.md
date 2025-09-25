# NdisRetreatNetBufferListDataStart function

## Description

Call the
**NdisRetreatNetBufferListDataStart** function to increase the
*used data space* in all the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures in a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NetBufferList` [in]

A pointer to a previously allocated NET_BUFFER_LIST structure.

### `DataOffsetDelta` [in]

The amount of additional
*used data space* in each NET_BUFFER structure. If there is not enough
*unused data space* to satisfy the request, NDIS allocates more memory.

### `DataBackFill` [in]

If NDIS must allocate memory, this parameter specifies the amount of data space in addition to the
value of the
*DataOffsetDelta* parameter to allocate.

### `AllocateMdlHandler` [in, optional]

An optional entry point for an
[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl) function. If the caller
specifies an entry point for the
*NetAllocateMdl* function, NDIS calls
*NetAllocateMdl* to allocate an MDL and memory.

### `FreeMdlHandler` [in, optional]

An optional entry point for an
[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl) function. If the caller
specifies an entry point for the
*NetFreeMdl* function, NDIS calls
*NetFreeMdl* to free an MDL and memory.

## Return value

**NdisRetreatNetBufferListDataStart** returns one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisRetreatNetBufferListDataStart** successfully allocated the data space on all the NET_BUFFER structures either by reducing the value of the **DataOffset** member or by allocating new storage. |
| **NDIS_STATUS_RESOURCES** | **NdisRetreatNetBufferListDataStart** failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | **NdisRetreatNetBufferListDataStart** failed for reasons other than insufficient resources. |

## Remarks

Calling
**NdisRetreatNetBufferListDataStart** is the equivalent of calling the
[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart) function for every
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure on the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.
**NdisRetreatNetBufferListDataStart** attempts to satisfy the request by reducing the value of the
**DataOffset** member in every NET_BUFFER structure. If there is not enough
*unused data space* available, this function allocates a new buffer and MDL, and then chains the new
MDL to the beginning of the MDL chain on the NET_BUFFER structure.

Call the
[NdisAdvanceNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferlistdatastart) function to release data space that was claimed in a previous
**NdisRetreatNetBufferListDataStart** call. Alternatively, the driver can call the
[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart) function for each NET_BUFFER structure on the NET_BUFFER_LIST
structure. Calling
**NdisAdvanceNetBufferListDataStart** is more efficient.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAdvanceNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferdatastart)

[NdisAdvanceNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisadvancenetbufferlistdatastart)

[NdisRetreatNetBufferDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferdatastart)

[NetAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_allocate_mdl)

[NetFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nc-nblapi-net_buffer_free_mdl)