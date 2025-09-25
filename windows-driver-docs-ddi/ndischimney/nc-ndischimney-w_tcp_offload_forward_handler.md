# W_TCP_OFFLOAD_FORWARD_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls the
*MiniportTcpOffloadForward* function to forward unacknowledged received TCP segments to an offload
target.

## Parameters

### `MiniportAdapterContext` [in]

The handle to an offload-target allocated context area in which the offload target maintains state
information about this instance of the adapter. The miniport driver provided this handle to NDIS when it
called
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportOffloadContext` [in]

A pointer to a memory location that contains a PVOID value. This PVOID value references the
miniport offload context that contains the state object for the TCP connection for which the TCP
segments are being forwarded. The offload target supplied this PVOID value when it offloaded the TCP
connection state object.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. This structure
may be a stand-alone structure or the first structure in a linked list of NET_BUFFER_LIST structures.
Each NET_BUFFER_LIST structure in the list describes one
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. Each NET_BUFFER structure
maps to a chain of memory descriptor lists (MDLs). The MDLs associated with a NET_BUFFER structure
contain one and only one TCP segment that is being forwarded to the offload target. The first byte of
the first MDL is the first byte of the TCP header. The NET_BUFFER_LIST and associated structures are
locked so that they remain resident in physical memory. However, they are not mapped into system
memory.

## Return value

NDIS_STATUS_PENDING is the only allowable return value. An offload target always completes a
forward request asynchronously by calling the
[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete) function.

## Remarks

The host stack forwards one or more TCP segments that it has received but not acknowledged in the
following situations:

* The host stack received the segments on a TCP connection that was being offloaded to the offload
  target. Since the connection was not fully offloaded, the offload target could not process the TCP
  segments at that time.
* The host stack is in a multihomed system that received the segments on a network interface other
  than the one on which the TCP connection is offloaded.
* The offload target previously indicated received packets that had IP options set and/or that were
  fragments that needed reassembling. After processing the IP options and/or successfully reassembling
  the packets, the host stack forwards the TCP segments to the offload target.

The host stack never attempts to forward TCP segments for a TCP connection when:

* That connection is being offloaded. The host stack always waits for the offload of the connection to
  complete before forwarding any packets for that connection. The host stack forwards TCP segments as
  soon as possible after the offload of the connection has completed. However, there is no time limit for
  forwarding such segments.
* The offload of that connection is being terminated. In this case, the host stack buffers the data
  until the termination of the offload completes and then processes the segments.

The host stack forwards TCP segments--not IP datagrams--to an offload target. Therefore, the only
header that the host stack supplies for each segment is the TCP header, including any TCP options that
are present. This is all the header information that the offload target needs to process the received
segment.

When forwarding TCP segments, the host stack transfers one TCP segment per NET_BUFFER structure. The
host stack associates just one NET_BUFFER structure, and therefore one forwarded TCP segment, with each
NET_BUFFER_LIST structure in the linked list.

The host stack allocates the NET_BUFFER_LIST and associated structures that NDIS passes to the
*MiniportTcpOffloadForward* function. The offload target owns these resources until it passes them to
the
[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete) function. While it owns these resources, the offload target is free
to queue them for processing.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisTcpOffloadForwardComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_forward_complete)