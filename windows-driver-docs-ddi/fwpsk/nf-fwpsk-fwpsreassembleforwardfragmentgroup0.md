# FwpsReassembleForwardFragmentGroup0 function

## Description

The
**FwpsReassembleForwardFragmentGroup0** function assembles a list of IP fragments in the forwarding data
path into a single packet.

**Note** **FwpsReassembleForwardFragmentGroup0** is a specific version of **FwpsReassembleForwardFragmentGroup**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `addressFamily` [in]

One of the following address families:

#### AF_INET

The IPv4 address family.

#### AF_INET6

The IPv6 address family.

### `fragmentGroupNblChain` [in, out]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain of IP fragments to
reassemble into a single packet. For more information on the usage of
this parameter, see Remarks.

### `netBufferAndNetBufferListPoolHandle` [in, optional]

An optional
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pool handle that
was previously returned from the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function. The
**fAllocateNetBuffer** member of the
[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters) structure that the caller passed to
**NdisAllocateNetBufferListPool** must have been set to **TRUE**, and the
**DataSize** member set to zero. If this parameter is **NULL**, NDIS uses an internal pool.

### `dataBackFill` [in]

If allocation of
unused data space (backfill space) is required, this parameter specifies the number of bytes of
unused data space to allocate.

### `flags` [in]

Reserved. Callout drivers must set this parameter to zero.

### `reassembledNbl` [out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) pointer that receives the
address of the reassembled single network buffer list.

## Return value

The
**FwpsReassembleForwardFragmentGroup0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The list of IP fragments was successfully reassembled into a single [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to perform packet reassembly. This error can occur if this function is called before Tcpip.sys is loaded, or after Tcpip.sys has been unloaded. |
| **Other status codes** | An error occurred. |

## Remarks

The
**FwpsReassembleForwardFragmentGroup0** function assembles a list of IP fragments in the forwarding
data path, described by a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain, into a single packet.
The reassembled packet is a single net buffer list that contains one net buffer and references the input
fragment chain. This function is typically used by edge firewalls to inspect network packets.

The input chain of IP fragments,
*fragmentGroupNblChain*, must be one that is indicated by the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function to the
FWPS_LAYER_IPFORWARD_V4 or FWPS_LAYER_IPFORWARD_V6 layer when the FWP_CONDITION_FLAG_IS_FRAGMENT_GROUP
flag is set. If this is not the case, the behavior of
**FwpsReassembleForwardFragmentGroup0** is undefined.

Call the
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) function to
free the
*reassembledNbl* NET_BUFFER_LIST structure and all of the associated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures and MDL chains.
**FwpsFreeNetBufferList0** dereferences the original input fragment chain.

You can use the following command to view the current "Group Forwarded Fragments" setting for the
system:
**netsh interface {ipv4|ipv6} show global**.

Because
**FwpsReassembleForwardFragmentGroup0** references the input fragment chain, it is not necessary for
callouts to reference or clone the chain prior to calling this function.

## See also

[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_POOL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/ns-nblapi-net_buffer_list_pool_parameters)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)