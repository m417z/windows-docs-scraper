# FwpsInjectTransportSendAsync1 function

## Description

The
**FwpsInjectTransportSendAsync1** function injects packet data from the transport, datagram data, or ICMP
error layers into the send data path. This function differs from the previous version
([FwpsInjectTransportSendAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync0)) in that it takes an updated parameters structure as an argument.

**Note** **FwpsInjectTransportSendAsync1** is the specific version of **FwpsInjectTransportSendAsync** used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows Vista, [FwpsInjectTransportSendAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync0) is available.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function.

### `injectionContext` [in, optional]

An optional handle to the injection context. If specified, it can be obtained by calling the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function when the packet injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) is
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**.

### `endpointHandle` [in]

A handle that indicates the stack transport endpoint in the send data path into which the packet
is to be injected. This endpoint handle is provided to a callout through the
**transportEndpointHandle** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. Callout
drivers should use the provided handle to inject cloned packets back into the data path as soon as
possible, before the socket associated with the stack endpoint is closed and the handle becomes no
longer valid.

### `flags` [in]

This parameter is reserved. Callout drivers must set this parameter to zero.

### `sendArgs` [in, optional]

A pointer to a
[FWPS_TRANSPORT_SEND_PARAMS1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_transport_send_params1_) structure that specifies the properties of the current outbound
packet. This parameter can be **NULL** only if the net buffer list to be injected contains an IP header (for
example, if the packet is sent through a raw socket).

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

### `netBufferList` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data that is being injected. A callout driver allocates a **NET_BUFFER_LIST** structure to use to
inject packet data by calling either the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function or the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function.

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
**FwpsInjectTransportSendAsync1** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The packet data injection was initiated successfully. The filter engine will call the completion function after the filter engine has completed injecting the packet data into the network stack, or when an error occurred subsequently. In case of an error, the **Status** member of the completed [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure will indicate the reason for failure. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to accept injection of packet data. |
| **STATUS_FWP_INJECT_HANDLE_CLOSING** | The injection handle is being closed. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpsInjectTransportSendAsync1** function to inject packet data from the transport, datagram data, or ICMP error layers into the send data path. At these layers, the IP header might not yet be formed, and when IPsec policy is active, the packet data is not encrypted or signed. Therefore, this function is ideal to use for packet inspection in an IPsec-enabled environment.

This function can execute asynchronously.

If the return value is not **STATUS_SUCCESS**, the completion function will not be called. In this case,
the net buffer list pointed to by
*netBufferList* must be freed by a call to
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) or
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0).

Callout drivers normally inject data into the network stack when they modify packet data. For more
information about how a callout driver can modify packet data, see
[Callout Driver Operations](https://learn.microsoft.com/windows-hardware/drivers/network/callout-driver-operations).

The injected packet can be indicated to the callout driver again. To prevent infinite looping, the
driver should first call the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function before calling the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function, and permit
packets that have the injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) set to
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**.

The
*endpointHandle* parameter and members declared in the
[FWPS_TRANSPORT_SEND_PARAMS1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_transport_send_params1_) structure pointed to by the
*sendArgs* parameter are provided to callouts from the following network layers:

FWPS_LAYER_OUTBOUND_TRANSPORT_V4

FWPS_LAYER_OUTBOUND_TRANSPORT_V6

FWPS_LAYER_DATAGRAM_DATA_V4 (when outbound direction is specified with FWP_DIRECTION_OUTBOUND)

FWPS_LAYER_DATAGRAM_DATA_V6 (when outbound direction is specified with FWP_DIRECTION_OUTBOUND)

FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4

FWPS_LAYER_OUTBOUND_ICMP_ERROR_V6

The datagram belongs to a raw socket if both of the following are true:

* The **currentMetadataValues** member of the [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure has the **FWPS_METADATA_FIELD_IP_HEADER_SIZE** flag set.
* The **ipHeaderSize** member of the [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure is greater than zero.

At the following network layers, if the datagram belongs to a raw socket, you'll need to copy the **headerIncludeHeader** and **headerIncludeHeaderLength** members of the [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure into the corresponding member of the [FWPS_TRANSPORT_SEND_PARAMS1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_transport_send_params1_) structure that the *sendArgs* parameter points to:

* FWPS_LAYER_DATAGRAM_DATA_V4 (when outbound direction is specified with FWP_DIRECTION_OUTBOUND)
* FWPS_LAYER_DATAGRAM_DATA_V6 (when outbound direction is specified with FWP_DIRECTION_OUTBOUND)

## See also

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_)

[FWPS_TRANSPORT_SEND_PARAMS1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_transport_send_params1_)

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0)

[FwpsInjectTransportSendAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportsendasync0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)