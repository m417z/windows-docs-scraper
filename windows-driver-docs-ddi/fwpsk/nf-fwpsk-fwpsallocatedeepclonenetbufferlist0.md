## Description

The **FwpsAllocateDeepCloneNetBufferList0** function allocates a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is a deep clone of an existing **NET_BUFFER_LIST** structure.

## Parameters

### `originalNetBufferList` [in, out]

A pointer to the original [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is being cloned.

### `netBufferListPoolHandle` [in, optional]

A [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool handle that was obtained from a previous call to the [**NdisAllocateNetBufferListPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function. This parameter is optional and can be **NULL**.

### `netBufferPoolHandle` [in, optional]

A [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool handle that was obtained from a previous call to the [**NdisAllocateNetBufferPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool) function. This parameter is optional and can be **NULL**.

### `netBufferList` [out]

A pointer to a variable that receives a pointer to the deep clone [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Return value

The **FwpsAllocateDeepCloneNetBufferList0** function returns one of the following NTSTATUS codes.

|Return code|Description|
|--- |--- |
|**STATUS_SUCCESS**|The deep clone [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure was successfully allocated.|
|**Other status codes**|An error occurred.|

## Remarks

A callout driver calls the **FwpsAllocateDeepCloneNetBufferList0** function to allocate a deep clone [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure of an existing **NET_BUFFER_LIST** structure.

This function is a wrapper around the [**NdisAllocateCloneNetBufferList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function, but it is specialized for use by WFP [packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions).

If the deep clone **NET_BUFFER_LIST** structure should have attributes that are associated with a specific pool, the callout driver must specify the pool handle in the _NetBufferListPoolHandle_ or _NetBufferPoolHandle_ parameter. If these parameters are **NULL**, the default pool preallocated by NDIS is used.

The deep clone **NET_BUFFER_LIST** structure describes the same data that is described by the original **NET_BUFFER_LIST** structure. The **FwpsAllocateDeepCloneNetBufferList0** function copies the data that is described by the original MDLs to new data buffers. The clone **NET_BUFFER_LIST** structure includes an initial [**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

This function sets the **ParentNetBufferList** member of the newly created clone **NET_BUFFER_LIST** structure to point to the parent **NET_BUFFER_LIST** structure. The parent structure's **ChildRefCount** member is incremented by **1**.

A callout driver can modify the clone **NET_BUFFER_LIST** structure and inject it into the network stack in place of the original **NET_BUFFER_LIST** structure by calling the [packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions). After the data described by the clone **NET_BUFFER_LIST** structure has been successfully injected into the network stack, the callout driver frees the clone **NET_BUFFER_LIST** structure by calling the [**FwpsFreeCloneNetBufferList0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) function.

A callout driver can insert or replace individual net buffers ([**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)) or MDLs inside the deep clone **NET_BUFFER_LIST**. The driver must undo these modifications before it calls the [**FwpsFreeCloneNetBufferList0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) function.

### Guidelines for managing cloned packets
A callout driver must not hold cloned packets indefinitely. A cloned packet can interfere with power management operations on an idle computer.

The intended use for deep cloned packets in WFP is to get clarification from a user-mode application or other relatively fast operation that needs a packet independent of the original. The callout driver must not hold cloned packets while waiting for user input, web service clearance, or any other operation that might take an arbitrary amount of time.

Callout drivers should always return held packets as quickly as possible.

## See also

[**FwpsFreeCloneNetBufferList0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[**NdisAllocateNetBufferListPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[**NdisAllocateNetBufferPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[Packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)