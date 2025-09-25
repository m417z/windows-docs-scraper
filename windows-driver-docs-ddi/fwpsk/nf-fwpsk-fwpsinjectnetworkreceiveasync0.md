# FwpsInjectNetworkReceiveAsync0 function

## Description

The
**FwpsInjectNetworkReceiveAsync0** function injects packet data into the receive data path.

**Note** **FwpsInjectNetworkReceiveAsync0** is a specific version of **FwpsInjectNetworkReceiveAsync**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function with the
*flags* parameter set to FWPS_INJECTION_TYPE_NETWORK.

### `injectionContext` [in, optional]

An optional handle to the injection context. If specified, it can be obtained by calling the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function when the packet injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) is
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**.

### `flags` [in]

Reserved. Callout drivers must set this parameter to zero.

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

The index of the interface on which the original packet data was received. A callout driver should
use the value of the interface index that is passed as one of the incoming data values to its
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for this
parameter if the packet is to be injected into the same interface where the original packet was
indicated.

### `subInterfaceIndex` [in]

The index of the subinterface on which the original packet data was received. A callout driver
should use the value of the subinterface index that is passed as one of the incoming data values to its
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for this
parameter if the packet is to be injected into the same subinterface where the original packet was
indicated.

### `netBufferList` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data that is being injected. A callout driver allocates a NET_BUFFER_LIST structure to use to
inject packet data by calling either the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function or the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function. The NET_BUFFER_LIST structure must begin with an
IP header.

### `completionFn` [in]

A pointer to a
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function provided by
the callout driver. The filter engine calls this function after the packet data, described by the
*netBufferList* parameter, has been injected into the network stack.

### `completionContext` [in, optional]

A pointer to a callout driver–provided context that is passed to the callout function pointed to
by the
*completionFn* parameter. This parameter is optional and can be **NULL**.

## Return value

The
**FwpsInjectNetworkReceiveAsync0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The packet data injection was initiated successfully. The filter engine will call the completion function after the filter engine has completed injecting the packet data into the network stack, or when an error occurred subsequently. In case of an error, the **Status** member of the completed [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure will indicate the reason for failure. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to accept injection of packet data. |
| **STATUS_FWP_INJECT_HANDLE_CLOSING** | The injection handle is being closed. |
| **STATUS_FWP_INJECT_HANDLE_STALE** | The injection handle was not created with the *flags* parameter of the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function set to FWPS_INJECTION_TYPE_NETWORK. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsInjectNetworkReceiveAsync0** function to inject packet data or a packet fragment into the receive
data path. This function can execute asynchronously. Callout drivers normally inject data into the
network stack when modifying packet data. For more information about how a callout driver can modify
packet data, see
[Callout Driver Operations](https://learn.microsoft.com/windows-hardware/drivers/network/callout-driver-operations).

If the return value is not STATUS_SUCCESS, the completion function will not be called. In this case,
the net buffer list pointed to by
*netBufferList* must be freed by a call to
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) or
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0).

The injected packet can be indicated to the callout driver again. To prevent infinite looping, the
driver should first call the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function before proceeding with a call to the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function, and the driver
should permit packets that have the injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) set to
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF** to pass through unaltered.

## See also

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_)

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)