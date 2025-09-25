# NET_BUFFER_SHARED_MEM_OFFSET macro

## Description

The **NET_BUFFER_SHARED_MEM_OFFSET** macro gets the shared memory offset from a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure.

## Syntax

```cpp
#define NET_BUFFER_SHARED_MEM_OFFSET(_SHI) ((_SHI)->SharedMemoryOffset)
```

## Parameters

### `_SHI`

A pointer to a **NET_BUFFER_SHARED_MEMORY** structure.

## Return value

**NET_BUFFER_SHARED_MEM_OFFSET** returns a ULONG value that contains the offset, in bytes, of the shared memory.

## Remarks

An NDIS 6.20 or later driver can use the **NET_BUFFER_SHARED_MEM_OFFSET** macro to get shared memory offset that is associated with a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure. **NET_BUFFER_SHARED_MEM_OFFSET** gets the offset from the **SharedMemoryOffset** member of the **NET_BUFFER_SHARED_MEMORY** structure. The **SharedMemoryInfo** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure contains the first **NET_BUFFER_SHARED_MEMORY** structure in a linked list.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory)