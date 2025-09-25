# FwpsInjectForwardAsync0 function

## Description

The
**FwpsInjectForwardAsync0** function injects packet data into the forwarding data path.

**Note** **FwpsInjectForwardAsync0** is a specific version of **FwpsInjectForwardAsync**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function.

### `injectionContext` [in, optional]

An optional handle to the injection context. If specified, it can be obtained by calling the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function when the packet injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) is
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**.

### `flags` [in]

Reserved. Callout drivers must set this parameter to zero.

### `addressFamily` [in]

One of the following address families:

#### AF_INET

The IPv4 address family.

#### AF_INET6

The IPv6 address family.

### `compartmentId` [in]

The identifier of the routing compartment into which the packet data is injected, specified as a
[COMPARTMENT_ID](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-compartment_id) type. This identifier is provided
to a callout through the
**compartmentId** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. If the
**compartmentId** member is available to callouts, FWPS_METADATA_FIELD_COMPARTMENT_ID will be set in
the
**currentMetadataValues** member. Otherwise, set this parameter to UNSPECIFIED_COMPARTMENT_ID.

### `interfaceIndex` [in]

The index of the destination interface (on which the packet data is to be sent). The index is a
32-bit value. A callout driver should use the value of the interface index that is passed as one of the
incoming data values to its
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for this
parameter if the packet is to be injected into the same interface where the original packet was
indicated.

### `netBufferList` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data that is being injected. A callout driver allocates a NET_BUFFER_LIST structure to inject
packet data by calling either the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function or the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function. The NET_BUFFER_LIST structure must begin with an
IP header.

### `completionFn` [in]

A pointer to a
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function provided by
the callout driver. The filter engine calls this function after the packet data, described by the
*netBufferList* parameter, has been injected into the network stack.

### `completionContext` [in, optional]

A pointer to a callout driver-provided context that is passed to the callout function pointed to
by the
*completionFn* parameter. This parameter is optional and can be **NULL**.

## Return value

The
**FwpsInjectForwardAsync0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The packet data injection was initiated successfully. The filter engine will call the completion function after the filter engine has completed injecting the packet data into the network stack, or when an error occurred subsequently, in which case the **Status** member of the completed [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure will indicate the reason for failure. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to accept injection of packet data. |
| **STATUS_FWP_INJECT_HANDLE_CLOSING** | The injection handle is being closed. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsInjectForwardAsync0** function to inject packet data or a packet fragment into the forwarding
data path.

This function can execute asynchronously. Callout drivers normally inject data into the network stack
when modifying packet data. For more information about how a callout driver can modify packet data, see
[Callout Driver Operations](https://learn.microsoft.com/windows-hardware/drivers/network/callout-driver-operations).

A packet or packet fragment injected with this function will not be indicated to any WFP layer for
filtering.

If the return value is not STATUS_SUCCESS, the completion function will not be called. In this case,
the net buffer list pointed to by
*netBufferList* must be freed by a call to
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) or
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0).

IP packets or fragments can be cloned, modified, and injected back into the network stack. However, a
fragment group must be reassembled by the callout driver as a single NET_BUFFER_LIST before it can be
reinjected.

Forward-injected packets do not reenter the forwarding layer. Therefore, they will not be
reclassified.

## See also

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Packet Injection Functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)