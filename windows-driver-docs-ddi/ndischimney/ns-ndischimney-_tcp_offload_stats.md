# _TCP_OFFLOAD_STATS structure

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

The TCP_OFFLOAD_STATS structure contains statistics that an offload target supplies in response to a
query of
[OID_TCP4_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp4-offload-stats) or
[OID_TCP6_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp6-offload-stats).

## Members

### `InSegments`

The total number of segments received on offloaded TCP connections, including those received in
error (
**InErrors** ). This count includes segments received on currently established connections. See
*tcpInSegs* in RFC 1156.

### `OutSegments`

The total number of segments sent on offloaded TCP connections, including those on current
connections but excluding those containing only retransmitted octets. See
*tcpOutSegs* in RFC 1156.

### `CurrentlyEstablished`

The number of TCP connections for which the current state is either ESTABLISHED or CLOSE-WAIT. See
*tcpCurrEstab* in RFC 1156.

### `ResetEstablished`

The number of times that offloaded TCP connections have made a direct transition to the CLOSED
state from either the ESTABLISHED state or the CLOSE-WAIT state.

### `RetransmittedSegments`

The total number of segments retransmitted on offloaded TCP connections--that is, the number of
TCP segments transmitted that contain one or more previously transmitted octets. See
*tcpRetransSegs* in RFC 1156.

### `InErrors`

The number of packets received on offloaded TCP connections that contained one or more
TCP-specific errors that prevented the offload target from delivering the packets. See
*ifInErrors* in RFC 1156.

### `OutResets`

The number of segments transmitted on offloaded TCP connections with the RST bit set in the TCP
header.

## Remarks

The statistics in the TCP_OFFLOAD_STATS structure pertain only to offloaded TCP connections. The
offload target must not include counts for TCP segments on connections that haven't been offloaded. The
statistics in the TCP_OFFLOAD_STATS structure pertain to a single network interface.

If an offload target has more than one network interface, it must maintain a separate set of TCP
statistics counters for each network interface. If the offload target supports both IPv4 and IPv6
connections on a network interface, it must, for that interface, maintain a separate set of TCP
statistics counters for TCP/IPv4 traffic and a separate set of TCP statistics counters for TCP/IPv6
traffic.

If an offload target's TCP chimney capabilities are enabled (see
[NDIS_TASK_OFFLOAD](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff558995(v=vs.85))) and if at least one
offloaded path state object has been offloaded to the offload target, the offload target can process a
received packet that has a corrupted TCP header (but a valid IP header) in one of two ways:

* The offload target can indicate the packet through the non-offload interface by calling the
  [NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function. In this case, the offload target must not increment
  the
  **InErrors** counter. This is the recommended approach.
* Alternatively, the offload target can drop the corrupted packet and increment the
  **InErrors** counter.

If the offload target's TCP chimney capabilities are not enabled or if there is not at least one
offloaded path state object, the offload target must indicate the corrupted packet and must not increment
the
**InErrors** counter.

The host stack integrates the statistics returned by an offload target with the statistics that the
host stack maintains for non-offloaded TCP connections.

Note that the host stack supplies a TCP_OFFLOAD_STATS structure when setting OID_TCP4_OFFLOAD_STATS or
OID_TCP6_OFFLOAD_STATS. In this case, however, the offload target does not have to examine the values in
the TCP_OFFLOAD_STATS structure. Instead, when OID_TCP4_OFFLOAD_STATS is set, the offload target should
reset to zero its TCP statistics counters for offloaded TCP connections that convey IPv4 datagrams. When
OID_TCP6_OFFLOAD_STATS is set, the offload target should reset to zero its TCP statistics counters for
offloaded TCP connections that convey IPv6 datagrams.

All of the counters that supply the values for the TCP_OFFLOAD_STATS structure wrap (restart from
zero) when incremented beyond their maximum counts.

## See also

[OID_TCP4_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp4-offload-stats)

[OID_TCP6_OFFLOAD_STATS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp6-offload-stats)