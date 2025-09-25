# NET_BUFFER_SHARED_MEM_FLAGS macro

## Description

The **NET_BUFFER_SHARED_MEM_FLAGS** macro gets the shared memory flags from a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure.

## Syntax

```cpp
#define NET_BUFFER_SHARED_MEM_FLAGS(_SHI) ((_SHI)->SharedMemoryFlags)
```

## Parameters

### `_SHI`

A pointer to a **NET_BUFFER_SHARED_MEMORY** structure.

## Return value

**NET_BUFFER_SHARED_MEM_FLAGS** returns a ULONG that contains shared memory flags.

## Remarks

An NDIS 6.20 or later driver can use the **NET_BUFFER_SHARED_MEM_FLAGS** macro to get shared memory flags that are associated with a [**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory) structure. **NET_BUFFER_SHARED_MEM_FLAGS** gets the flags from the **SharedMemoryFlags** member of the **NET_BUFFER_SHARED_MEMORY** structure. The **SharedMemoryInfo** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure contains the first **NET_BUFFER_SHARED_MEMORY** structure in a linked list.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_SHARED_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_shared_memory)