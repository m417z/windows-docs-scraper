# FWPS_NET_BUFFER_LIST_EVENT_TYPE0_ enumeration

## Description

The **FWPS_NET_BUFFER_LIST_EVENT_TYPE0** enumeration type specifies the possible status events that can
cause the callout driver's
[FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0) function to be called.

**Note** **FWPS_NET_BUFFER_LIST_EVENT_TYPE0** is a specific version of **FWPS_NET_BUFFER_LIST_EVENT_TYPE**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Constants

### `FWPS_NET_BUFFER_LIST_ENTERED_NETIO`

The [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure entered the TCP/IP stack. Packets enter the stack either from
the NDIS layer or as a result of a call to a WFP packet injection function.

### `FWPS_NET_BUFFER_LIST_CLONED_BY_NETIO`

The NET_BUFFER_LIST structure was cloned.

### `FWPS_NET_BUFFER_LIST_CLONED_VIA_WFP_API`

The NET_BUFFER_LIST structure was cloned by a call to the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function.

### `FWPS_NET_BUFFER_LIST_DUPLICATED_BY_NETIO`

The NET_BUFFER_LIST structure was duplicated.

### `FWPS_NET_BUFFER_LIST_EXIT_NETIO`

The NET_BUFFER_LIST structure is about to leave the TCP/IP stack.

### `FWPS_NET_BUFFER_LIST_CONTEXT_REMOVED`

The NET_BUFFER_LIST structure is outside of the context for which it was tagged. The
circumstances for this event depend upon the specifics of the tagged packets.

| Packet Type | Event Condition |
| --- | --- |
| Outbound | The NET_BUFFER_LIST structure exits the TCP/IP stack. |
| Any | Upon asynchronous context removal resulting from a call to the [FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0) function. |

### `FWPS_NET_BUFFER_LIST_NDIS_SEND_COMPLETE`

See FWPS_NET_BUFFER_LIST_NDIS_ETHERNET_SEND_COMPLETE.

### `FWPS_NET_BUFFER_LIST_NDIS_RECV_COMPLETE`

See FWPS_NET_BUFFER_LIST_NDIS_ETHERNET_RECV_COMPLETE.

### `FWPS_NET_BUFFER_LIST_NDIS_ETHERNET_SEND_COMPLETE`

The NET_BUFFER_LIST structure send over the upper (protocol driver) NDIS 802.3 layer is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_NDIS_ETHERNET_RECV_COMPLETE`

The NET_BUFFER_LIST structure receive over the upper (protocol driver) NDIS 802.3 layer is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_NDIS_NATIVE_SEND_COMPLETE`

The NET_BUFFER_LIST structure send over the lower (miniport driver) NDIS native layer is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_NDIS_NATIVE_RECV_COMPLETE`

The NET_BUFFER_LIST structure receive over the lower (miniport driver) NDIS native layer is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_NDIS_VSWITCH_INGRESS_COMPLETE`

The NET_BUFFER_LIST structure ingress on the virtual switch is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_NDIS_VSWITCH_EGRESS_COMPLETE`

The NET_BUFFER_LIST structure egress on the virtual switch is complete.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_CLONED_BY_NDIS`

NDIS cloned the NET_BUFFER_LIST structure.

**Note** Supported starting with Windows 8.

### `FWPS_NET_BUFFER_LIST_REASSEMBLED_FRAGMENT`

The NET_BUFFER_LIST structure is a reassembled fragment.

**Note** Supported starting with Windows 8.1.

### `FWPS_NET_BUFFER_LIST_REASSEMBLY_COMPLETE`

The NET_BUFFER_LIST fragment reassembly is complete.

**Note** Supported starting with Windows 8.1.

## See also

[FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0)

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsNetBufferListRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistremovecontext0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)