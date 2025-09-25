# _NDIS_SCATTER_GATHER_LIST_PARAMETERS structure

## Description

The NDIS_SCATTER_GATHER_LIST_PARAMETERS structure specifies parameters that NDIS uses to build a
scatter/gather list for a buffer.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
structure (NDIS_SCATTER_GATHER_LIST_PARAMETERS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_SCATTER_GATHER_LIST_PARAMETERS_REVISION_1 and the
**Size** member to NDIS_SIZEOF_SCATTER_GATHER_LIST_PARAMETERS_REVISION_1.

### `Flags`

Reserved for NDIS.

### `QueueId`

An NDIS_RECEIVE_QUEUE_ID type value that contains a queue identifier. The queue identifier is an
integer between zero and the number of queues that the miniport adapter supports. A zero value indicates
the default queue.

### `SharedMemoryUsage`

An
[NDIS_SHARED_MEMORY_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_shared_memory_usage) enumeration
value that specifies the purpose of the shared memory.

### `Mdl`

A pointer to a memory descriptor list (MDL) that describes the shared memory buffer.

### `CurrentVa`

A ULONG value for the current virtual address.

### `Length`

A ULONG value that contains the length, in bytes, of the shared memory buffer.

### `ProcessSGListHandler`

A pointer to a
[NetProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_process_sg_list) function
(NDIS_PROCESS_SG_LIST_HANDLER entry point).

### `Context`

A pointer to a block of driver-allocated context information that stores information about the
scatter/gather list. NDIS passes the context information in calls to
[NetProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_process_sg_list) at the
*Context* parameter.

### `ScatterGatherListBuffer`

A pointer to a
[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure.

### `ScatterGatherListBufferSize`

A ULONG value that contains the length, in bytes, of the scatter/gather list.

### `ScatterGatherListBufferSizeNeeded`

A ULONG value where NDIS writes the total number of bytes that NDIS requires to build the
scatter/gather list successfully.

## Remarks

To build a scatter/gather list, an NDIS driver passes the NDIS_SCATTER_GATHER_LIST_PARAMETERS
structure to the
[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SHARED_MEMORY_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_shared_memory_usage)

[NdisBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisbuildscattergatherlist)

[NetProcessSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_process_sg_list)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)