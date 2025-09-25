# FwpsAllocateCloneNetBufferList0 function

## Description

The
**FwpsAllocateCloneNetBufferList0** function allocates a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is a clone of an existing
**NET_BUFFER_LIST** structure.

**Note** **FwpsAllocateCloneNetBufferList0** is a specific version of **FwpsAllocateCloneNetBufferList**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `originalNetBufferList` [in, out]

A pointer to the original
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that is being
cloned.

### `netBufferListPoolHandle` [in, optional]

A
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool handle that was
obtained from a previous call to the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function. This parameter is optional and can be **NULL**.

### `netBufferPoolHandle` [in, optional]

A
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) pool handle that was obtained from a
previous call to the
[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool) function. This parameter is optional and can be **NULL**.

### `allocateCloneFlags` [in]

There are currently no flags defined for this function. Callout drivers should set this parameter
to zero.

### `netBufferList` [out]

A pointer to a variable that receives a pointer to the clone
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Return value

The
**FwpsAllocateCloneNetBufferList0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The clone [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure was successfully allocated. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsAllocateCloneNetBufferList0** function to allocate a clone
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure of an existing
NET_BUFFER_LIST structure.

This function is a wrapper around the
[NdisAllocateCloneNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocateclonenetbufferlist) function, but it is specialized for use by WFP
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions).

If the clone NET_BUFFER_LIST structure should have attributes that are associated with a specific pool,
the callout driver must specify the pool handle in the
*NetBufferListPoolHandle* or
*NetBufferPoolHandle* parameter. If these parameters are **NULL**, the default pool preallocated by NDIS
is used.

The clone NET_BUFFER_LIST structure describes the same data that is described by the original
NET_BUFFER_LIST structure. The
**FwpsAllocateCloneNetBufferList0** function does not copy the data that is described by the original
MDLs to new data buffers. Instead, the clone NET_BUFFER_LIST structure references the original data
buffers. The clone NET_BUFFER_LIST structure does not include an initial
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

This function sets the
**ParentNetBufferList** member of the newly created clone NET_BUFFER_LIST structure to point to the
parent NET_BUFFER_LIST structure. The parent structure's
**ChildRefCount** member is incremented by 1.

A callout driver can modify the clone NET_BUFFER_LIST structure and inject it into the network stack
in place of the original NET_BUFFER_LIST structure by calling the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions). After
the data described by the clone NET_BUFFER_LIST structure has been successfully injected into the network
stack, the callout driver frees the clone NET_BUFFER_LIST structure by calling the
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) function.

A callout driver can insert or replace individual net buffers ([NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)) or MDLs inside the clone net buffer
list. Such a driver must also undo the modifications before it calls the
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) function.

### Guidelines for Managing Cloned Packets

A callout driver must not hold cloned packets indefinitely. A cloned packet can interfere with power
management operations on an idle computer.

The intended use for cloned packets in WFP is to get clarification from a user-mode application or
other relatively fast operation. The callout driver must not hold cloned packets while, for example,
waiting for user input, or waiting for web service clearance, or waiting for any other operation that
might take an arbitrary amount of time.

If the callout driver needs to wait for a potentially lengthy operation, it makes a deep copy of
the packet using
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0), and it blocks and absorbs the original packet.

Callout drivers should always return held packets as quickly as possible.

## See also

[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[Packet Injection Functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)