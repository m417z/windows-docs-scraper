# FwpsAllocateNetBufferAndNetBufferList0 function

## Description

The
**FwpsAllocateNetBufferAndNetBufferList0** function allocates a new
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

**Note** **FwpsAllocateNetBufferAndNetBufferList0** is a specific version of **FwpsAllocateNetBufferAndNetBufferList**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `poolHandle` [in]

A
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pool handle that was
obtained from a previous call to the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function.

### `contextSize` [in]

The size, in bytes, of used data space in the
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure
to reserve for the callout driver. The value of this parameter must be a multiple of the value defined
by **MEMORY_ALLOCATION_ALIGNMENT**.

### `contextBackFill` [in]

The size, in bytes, of
unused data space (backfill space) that the callout driver requires. The
**FwpsAllocateNetBufferAndNetBufferList0** function adds this value to the value specified in the
*ContextSize* parameter and allocates additional space. The value of this parameter must be a
multiple of the value defined by **MEMORY_ALLOCATION_ALIGNMENT**.

### `mdlChain` [in, optional]

A pointer to an MDL chain that is used to initialize the preallocated NET_BUFFER structure. This
parameter is optional and can be **NULL**.

### `dataOffset` [in]

The initial offset, in bytes, from the start of the buffer to the start of the
used data space in the MDL chain. Data space ahead of this offset is
unused data space. Therefore, this value also represents the initial amount of available backfill
space in the MDL chain.

### `dataLength` [in]

The length, in bytes, of the
used data space in the MDL chain.

### `netBufferList` [out]

A pointer to a variable that receives a pointer to the new
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Return value

The
**FwpsAllocateNetBufferAndNetBufferList0** function returns one of the following NTSTATUS
codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The new [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure was successfully allocated. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsAllocateNetBufferAndNetBufferList0** function to allocate a new
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

This function is a wrapper around the
[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist) function, but it is specialized for use by WFP
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions).

After the data described by the new [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure has been successfully injected into the
network stack, the callout driver frees the new **NET_BUFFER_LIST** structure by calling the
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) function.

## See also

[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisAllocateNetBufferAndNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferandnetbufferlist)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[Packet Injection Functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)