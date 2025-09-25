# NdisAllocateNetBufferListContext function

## Description

Call the
**NdisAllocateNetBufferListContext** function to allocate more context space in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure of a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `NetBufferList` [in]

A pointer to a previously allocated NET_BUFFER_LIST structure.

### `ContextSize` [in]

The amount of context space to allocate in the NET_BUFFER_LIST_CONTEXT structure. This amount must
be a multiple of the value defined by `sizeof(void*)`.

### `ContextBackFill` [in]

The amount of memory, in addition to the value of
*ContextSize*, to allocate if NDIS must allocate memory to satisfy the request. This amount must be
a multiple of the value defined by `sizeof(void*)`.

### `PoolTag` [in]

A kernel pool tag that NDIS uses to allocate the memory for the NET_BUFFER_LIST_CONTEXT structure,
if allocation is required. The tag is a string, delimited by single quotation marks, with up to four
characters, usually specified in reversed order. The kernel pool tag helps NDIS to identify the owner of
the memory.

## Return value

**NdisAllocateNetBufferListContext** returns one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | **NdisAllocateNetBufferListContext** successfully allocated context space either by reducing the value of the **Offset** member of the NET_BUFFER_LIST_CONTEXT structure or by allocating new memory. |
| **NDIS_STATUS_RESOURCES** | **NdisAllocateNetBufferListContext** failed due to insufficient resources. |
| **NDIS_STATUS_FAILURE** | **NdisAllocateNetBufferListContext** failed for reasons other than insufficient resources. |

## Remarks

If there is enough unused context space available in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure to
satisfy the request,
**NdisAllocateNetBufferListContext** simply reduces the value of the
**Offset** member in the NET_BUFFER_LIST_CONTEXT structure. Otherwise, NDIS allocates new memory for
context space. You can specify
*ContextBackFill* to allocate extra memory so that the next call to
**NdisAllocateNetBufferListContext** does not have to allocate memory.

**Note** The context space is always aligned to `sizeof(void*)`.
This is adequate alignment for all natural types, but it is not adequate for datatypes with unusual alignment requirements, like SLIST_ENTRY.

Call the
[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext) function to release the context space in the NET_BUFFER_LIST_CONTEXT
structure that was allocated with
**NdisAllocateNetBufferListContext**.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisFreeNetBufferListContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferlistcontext)