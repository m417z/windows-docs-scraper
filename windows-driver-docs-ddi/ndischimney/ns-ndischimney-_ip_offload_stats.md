# _IP_OFFLOAD_STATS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The IP_OFFLOAD_STATS structure contains statistics that an offload target supplies in response to a
query of
[OID_IP4_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ip4-offload-stats) or
[OID_IP6_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ip6-offload-stats).

## Members

### `InReceives`

The total number of input IP datagrams that have been received from the interface on offloaded TCP
connections, including IP datagrams received in error. See
"ipInReceives" in RFC 2011.

### `InOctets`

The total number of octets (bytes) in input IP datagrams that have been received from the
interface on offloaded TCP connections. Octets from datagrams counted in
**InReceives** must be counted here.
**InOctets** must include the number of bytes in the IP header and payload.

### `InDelivers`

The number of input IP datagrams that were successfully delivered to offloaded TCP connections.
See
"ipInDelivers" in RFC 2011.

### `OutRequests`

The number of IP datagrams that the offload target supplied to its IP layer in requests for
transmission on offloaded TCP connections. See
"ipOutRequests" in RFC 2011.

### `OutOctets`

The total number of octets (bytes) in IP datagrams that the offload target supplied to its IP
layer in requests for transmission on offloaded TCP connections. Octets from datagrams counted in
**OutRequests** must be counted here.
**OutOctets** must include the number of bytes in the IP header and payload.

### `InHeaderErrors`

The number of input IP datagrams received on offloaded TCP connections that were discarded because
of errors in their IP headers. Such errors include bad checksums, version number mismatch, other format
errors, time-to-live exceeded, and errors discovered in processing IPv6 options if the offload target
supports such options. (An offload target does not process IPv4 options.) This count does not include
errors resulting from invalid destination addresses. See
"ipInHdrErrors" in RFC 2011.

### `InTruncatedPackets`

The number of input IP datagrams discarded because the datagram frame didn't carry enough data.
**InTruncatedPackets** should only be incremented if the frame contained a valid header but was
otherwise shorter than required. Frames that are too short to contain a valid header should be counted
as
**InHeaderErrors** .

### `InDiscards`

The number of input IP datagrams received on offloaded TCP connections that contained nothing to
prevent their further processing but that were discarded for run-time reasons, such as a lack of
available memory or other resources. See
"ipInDiscards" in RFC 2011.

### `OutDiscards`

The number of output IP datagrams that the offload target supplied to its IP layer for which no
problem was encountered to prevent their transmission but that were discarded for run-time reasons, such
as a lack of memory or other resources. See
"ipOutDiscards" in RFC 2011.

### `OutNoRoutes`

The number of output IP datagrams that the offload target supplied to its IP layer that were
discarded because no route (such as an offloaded path state object) could be found to transmit them to
their destination. See
"ipOutNoRoutes" in RFC 2011.

## Remarks

The statistics in the IP_OFFLOAD_STATS structure pertain only to IP datagrams that the offload target
has processed on offloaded TCP connections. The offload target must not include counts for IP datagrams
on non-offloaded connections. The statistics pertain to a single network interface.

If an offload target has multiple network interfaces, it must maintain separate IP offload statistics
for each network interface. If the offload target supports both IPv4 and IPv6 connections for a network
interface, it must maintain one set of IPv4 offload statistics counters and another set of IPv6 offload
statistics counters for that network interface.

If an offload target's TCP chimney capabilities are enabled (see
[NDIS_TASK_OFFLOAD](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff558995(v=vs.85))) and if at least one
neighbor state object has been offloaded to the offload target, the offload target can process a received
packet that has a corrupted IP header in one of two ways:

* The offload target can indicate the packet through the non-offload interface by calling the
  [NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function. In this case, the offload target must not increment
  the InHeaderErrors counter. This is the recommended approach.
* Alternatively, the offload target can drop the corrupted packet
  [NDIS_TASK_OFFLOAD](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff558995(v=vs.85)) and increment the
  InHeaderErrors counter.

The host stack integrates the statistics returned by an offload target with the statistics that the
host stack maintains for non-offloaded TCP connections.

Note that the host stack supplies an IP_OFFLOAD_STATS structure when setting OID_IP4_OFFLOAD_STATS or
OID_IP6_OFFLOAD_STATS. In either case, however, the offload target does not have to examine the values in
the IP_OFFLOAD_STATS structure. Instead, when OID_IP4_OFFLOAD_STATS is set, the offload target should
reset all of its IPv4 statistics counters for offloaded TCP connections. When OID_IP6_OFFLOAD_STATS is
set, the offload target should reset all of its IPv6 statistics counters for offloaded TCP
connections.

All of the counters that supply the values for the IP_OFFLOAD_STATS structure wrap (restart from zero)
when incremented beyond their maximum counts.

## See also

[NDIS_TASK_OFFLOAD](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff558995(v=vs.85))

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[OID_IP4_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ip4-offload-stats)

[OID_IP6_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ip6-offload-stats)