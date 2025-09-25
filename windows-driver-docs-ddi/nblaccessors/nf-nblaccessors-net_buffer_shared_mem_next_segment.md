# NET_BUFFER_SHARED_MEM_NEXT_SEGMENT macro

## Description

The **NET_BUFFER_SHARED_MEM_NEXT_SEGMENT** macro gets the next shared memory segment from a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure.

## Syntax

```cpp
#define NET_BUFFER_SHARED_MEM_NEXT_SEGMENT(_SHI) ((_SHI)->NextSharedMemorySegment)
```

## Parameters

### `_SHI`

A pointer to a **NET_BUFFER_SHARED_MEMORY** structure.

## Return value

**NET_BUFFER_SHARED_MEM_NEXT_SEGMENT** returns a pointer to a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure or returns **NULL**.

## Remarks

An NDIS 6.20 or later driver can use the **NET_BUFFER_SHARED_MEM_NEXT_SEGMENT** macro to get the next shared memory segment in a linked list of [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structures that are associated with a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. **NET_BUFFER_SHARED_MEM_NEXT_SEGMENT** gets a pointer to the next **NET_BUFFER_SHARED_MEMORY** structure from the **NextSharedMemorySegment** member of the **NET_BUFFER_SHARED_MEMORY** structure. The **SharedMemoryInfo** member of the **NET_BUFFER** structure contains the first **NET_BUFFER_SHARED_MEMORY** structure in the linked list.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory)