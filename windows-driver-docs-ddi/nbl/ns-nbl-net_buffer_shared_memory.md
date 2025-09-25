# _NET_BUFFER_SHARED_MEMORY structure

## Description

The NET_BUFFER_SHARED_MEMORY structure specifies a shared memory buffer that is associated with a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Members

### `NextSharedMemorySegment`

A pointer to the next NET_BUFFER_SHARED_MEMORY structure in a NULL-terminated linked list of such
structures.

### `SharedMemoryFlags`

A ULONG value that contains shared memory flags. This member is reserved for future use.

### `SharedMemoryHandle`

An NDIS_HANDLE that contains an NDIS shared memory handle.

### `SharedMemoryOffset`

A ULONG value that contains the offset, in bytes, of the shared memory.

### `SharedMemoryLength`

A ULONG value for the length, in bytes, of the shared memory segment.

## Remarks

An NDIS 6.20 or later driver uses the NET_BUFFER_SHARED_MEMORY structure to describe a shared memory
buffer. There can be a linked list of such shared memory buffers that are associated with a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. Virtual machine queue (VMQ)
capable NICs use these shared memory buffers in the virtualization environment.

Use the
[NET_BUFFER_SHARED_MEM_NEXT_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-next-segment),
[NET_BUFFER_SHARED_MEM_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-flags),
[NET_BUFFER_SHARED_MEM_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-handle),
[NET_BUFFER_SHARED_MEM_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-offset),
and
[NET_BUFFER_SHARED_MEM_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-length) macros to access the NET_BUFFER_SHARED_MEMORY in a NET_BUFFER
structure. The
**SharedMemoryInfo** member of the NET_BUFFER structure contains the first NET_BUFFER_SHARED_MEMORY
structure in the linked list.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_SHARED_MEM_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-flags)

[NET_BUFFER_SHARED_MEM_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-handle)

[NET_BUFFER_SHARED_MEM_LENGTH](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-length)

[NET_BUFFER_SHARED_MEM_NEXT_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-next-segment)

[NET_BUFFER_SHARED_MEM_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-shared-mem-offset)