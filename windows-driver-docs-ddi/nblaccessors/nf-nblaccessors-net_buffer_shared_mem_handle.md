# NET_BUFFER_SHARED_MEM_HANDLE macro

## Description

The **NET_BUFFER_SHARED_MEM_HANDLE** macro gets the shared memory handle from a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure.

## Syntax

```cpp
#define NET_BUFFER_SHARED_MEM_HANDLE(_SHI) ((_SHI)->SharedMemoryHandle)
```

## Parameters

### `_SHI`

A pointer to a **NET_BUFFER_SHARED_MEMORY** structure.

## Return value

**NET_BUFFER_SHARED_MEM_HANDLE** returns an NDIS shared memory handle.

## Remarks

An NDIS 6.20 or later driver can use the **NET_BUFFER_SHARED_MEM_HANDLE** macro to get the shared memory handle that is associated with a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure. **NET_BUFFER_SHARED_MEM_HANDLE** gets the handle from the **SharedMemoryHandle** member of the **NET_BUFFER_SHARED_MEMORY** structure. The **SharedMemoryInfo** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure contains the first **NET_BUFFER_SHARED_MEMORY** structure in a linked list.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory)