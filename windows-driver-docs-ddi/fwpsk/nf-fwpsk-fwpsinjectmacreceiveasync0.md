# FwpsInjectMacReceiveAsync0 function

## Description

The **FwpsInjectMacReceiveAsync0** function can reinject a previously absorbed media access control (MAC) frame (or a clone of the frame) back to the layer 2 inbound data path from which it was intercepted, or inject an invented MAC frame.

**Note** **FwpsInjectMacReceiveAsync0** is a specific version of **FwpsInjectMacReceiveAsync**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously obtained by a call to the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function with the *flags* parameter set to FWPS_INJECTION_TYPE_L2.

**Note** Set the *addressFamily* parameter of the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function to AF_UNSPEC.

### `injectionContext` [in, optional]

An optional handle to the injection context. If specified, it can be obtained by calling the
[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function when the packet injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) is
**FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**.

### `flags` [in]

Reserved. Must be set to zero.

### `layerId` [in]

The run-time identifier for the filtering layer at which the data stream is being processed.

### `interfaceIndex` [in]

The interface index that is passed to the callout driver's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) incoming value FWPS_FIELD_*Xxx*_MAC_FRAME_*Xxx*_INTERFACE_INDEX.

### `NdisPortNumber` [in]

The NDIS port number that is passed to the callout driver's [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) incoming value FWPS_FIELD_*Xxx*_MAC_FRAME_*Xxx*_NDIS_PORT.

### `netBufferLists` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data that is being injected. A callout driver allocates a NET_BUFFER_LIST structure to use to
inject packet data by calling either the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function or the
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function.
When `(layerId == FWPS_LAYER_INBOUND_MAC_FRAME_ETHERNET)`, the NET_BUFFER_LIST must begin with an Ethernet header.

When `(layerId == FWPS_LAYER_INBOUND_MAC_FRAME_NATIVE)`, the NET_BUFFER_LIST must begin with a MAC header.

### `completionFn` [in]

A pointer to a
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function provided by
the callout driver. The filter engine calls this function after the packet data, described by the
*netBufferLists* parameter, has been injected into the network stack. This pointer must be specified when injecting cloned or created NET_BUFFER_LIST structures. When injecting original NET_BUFFER_LIST structures, this parameter can be NULL if the original structures are not altered.

### `completionContext` [in, optional]

A pointer to a callout driver–provided context that is passed to the callout function pointed to
by the
*completionFn* parameter. This parameter is optional and can be **NULL**.

## Return value

The
**FwpsInjectMacReceiveAsync0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The MAC frame data injection was initiated successfully. The filter engine calls the completion function after the filter engine has completed injecting the MAC frame data, or when an error occurred subsequently. In case of an error, the **Status** member of the completed [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure will indicate the reason for failure. |
| **STATUS_FWP_TCPIP_NOT_READY** | The MAC layer is not ready to accept injection of packet data. |
| **STATUS_FWP_INJECT_HANDLE_CLOSING** | The injection handle is being closed. |
| **STATUS_FWP_INJECT_HANDLE_STALE** | The injection handle was not created with the *flags* parameter of the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function set to FWPS_INJECTION_TYPE_L2. |
| **Other status codes** | An error occurred. |

## Remarks

A callback driver calls the **FwpsInjectMacReceiveAsync0** function to reinject a previously absorbed MAC frame (or a clone of the frame) back to the layer 2 inbound data path from which it was intercepted, or to inject an invented MAC frame.

The *netBufferLists* parameter can be a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain. However the completion function could be invoked multiple times each, completing a segment (or single NET_BUFFER_LIST) of the chain.

Injected frames could get classified again if the packets match the same filter as originally classified. Therefore, as with callouts at IP layers, layer 2 callouts must also protect against infinite packet inspection by calling [FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0).

## See also

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)