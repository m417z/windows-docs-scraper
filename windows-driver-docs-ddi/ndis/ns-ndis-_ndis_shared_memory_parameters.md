# _NDIS_SHARED_MEMORY_PARAMETERS structure

## Description

The NDIS_SHARED_MEMORY_PARAMETERS structure specifies the shared memory parameters for a shared
memory allocation request.

## Members

### `Header`

The type, revision, and size of the NDIS_SHARED_MEMORY_PARAMETERS structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the NDIS_SHARED_MEMORY_PARAMETERS structure, the driver must set the **Revision** member of **Header** to one of the following values:

#### NDIS_SHARED_MEMORY_PARAMETERS_REVISION_2

Added **VPortId** for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_SHARED_MEMORY_PARAMETERS_REVISION_2.

#### NDIS_SHARED_MEMORY_PARAMETERS_REVISION_1

Original version for NDIS 6.20.

Set the **Size** member to NDIS_SIZEOF_SHARED_MEMORY_PARAMETERS_REVISION_1.

### `Flags`

A UCHAR value that contains a bitwise OR of the following value:

#### NDIS_SHARED_MEM_PARAMETERS_CONTIGOUS

The shared memory is in a contiguous block of memory.

### `QueueId`

An NDIS_RECEIVE_QUEUE_ID value that contains a virtual machine queue (VMQ) or single root I/O virtualization (SR-IOV) receive queue identifier. This identifier is an
integer between zero and the number of queues that the miniport adapter supports. A value of NDIS_DEFAULT_RECEIVE_QUEUE_ID specifies
the default receive queue.

**Note** Starting with Windows Server 2012, the SR-IOV interface only supports the default receive queue on both default and nondefault virtual ports (VPorts). Miniport drivers that support the SR-IOV interface must set the **QueueId** member to NDIS_DEFAULT_RECEIVE_QUEUE_ID.

### `SharedMemoryHandle`

An NDIS_HANDLE value that identifies a block of shared memory. NDIS provides this handle before it
returns from the
[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory) function.

### `PreferredNode`

A NODE_REQUIREMENT value that indicates the preferred node to use while allocating memory. If the driver does not have a preference, then the value must be set to MM_ANY_NODE_OK.

### `Usage`

An
[NDIS_SHARED_MEMORY_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_shared_memory_usage) enumeration
value that specifies the purpose of the shared memory.

### `Length`

A ULONG value that contains the length, in bytes, of the shared memory block.

### `VirtualAddress`

A PVOID value that contains the base virtual address of the shared memory. NDIS provides this
value before it returns from the
**NdisAllocateSharedMemory** function.

### `SGListBufferLength`

A ULONG value that contains the length, in bytes, of the scatter gather list buffer.

### `SGListBuffer`

A pointer to a
[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure.

### `VPortId`

An NDIS_NIC_SWITCH_VPORT_ID value that specifies a virtual port (VPort) identifier on which the shared memory is to be allocated. This value must be the identifier of a nondefault VPort that is attached to the physical function (PF) of the miniport adapter.

**Note** Miniport drivers that support the VMQ interface must set this member to zero. Miniport drivers that support the SR-IOV interface must not set this member to zero (NDIS_DEFAULT_VPORT_ID).

## Remarks

The NDIS_SHARED_MEMORY_PARAMETERS structure specifies the shared memory parameters for a shared memory
allocation request for a receive queue.

NDIS drivers pass this structure to the
[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory) function
and NDIS passes this structure to the
[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler) function
(ALLOCATE_SHARED_MEMORY_HANDLER entry point).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_SHARED_MEMORY_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-_ndis_shared_memory_usage)

[NdisAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatesharedmemory)

[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)