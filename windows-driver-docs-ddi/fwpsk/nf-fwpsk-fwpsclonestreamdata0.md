# FwpsCloneStreamData0 function

## Description

The
**FwpsCloneStreamData0** function allocates a clone of an existing
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) data stream.

**Note** **FwpsCloneStreamData0** is a specific version of **FwpsCloneStreamData**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `calloutStreamData` [in, out]

A pointer to the original
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure that is to
have its
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure cloned.

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

### `netBufferListChain` [out]

A pointer to a location that receives a pointer to a chain of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that describe
all of the cloned stream data.

## Return value

The
**FwpsCloneStreamData0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The clone [FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure was successfully allocated. |
| **Other status codes** | An error occurred. |

## Remarks

This cloned stream data can be injected by a callout driver into the TCP/IP network stack at a later
time.

The
**FwpsCloneStreamData0** function clones the entire chain of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures contained in the
existing
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) data stream. The
function trims unused data such that a callout driver can successfully pass the cloned chain to the
[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0) function.

After stream data in the clone NET_BUFFER_LIST structure chain has been successfully injected into the
network stack, the
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function is called for
each clone NET_BUFFER_LIST structure, and a callout should call
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) to
free the clone NET_BUFFER_LIST structure.

A callout should call the
[FwpsDiscardClonedStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsdiscardclonedstreamdata0) function if the cloned stream data is to be discarded without being
reinjected.

## See also

[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_)

[FwpsDiscardClonedStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsdiscardclonedstreamdata0)

[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)