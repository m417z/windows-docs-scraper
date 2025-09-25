## Description

Defines the possible reasons that data is discarded by one of the transport layers.

## Constants

### `InetDiscardSourceUnspecified:0`

The outgoing packet's source address is unspecified.

### `InetDiscardDestinationMulticast:1`

The outgoing packet's destination address is an unspecified address, and the transport does not support multicast addresses.

### `InetDiscardHeaderInvalid:2`

The packet has an invalid header.

### `InetDiscardChecksumInvalid:3`

The packet's checksum did not match.

### `InetDiscardEndpointNotFound:4`

The intended endpoint for the packet could not be found.

### `InetDiscardConnectedPath:5`

The packet remote address does not match the remote address of a connected endpoint.

### `InetDiscardSessionState:6`

The packet cannot be delivered based on network layer information.

### `InetDiscardReceiveInspection:7`

The connection was closed due to a receive inspection failure.

### `InetDiscardAckInvalid:8`

The packet is an invalid ACK segment.

### `InetDiscardExpectedSyn:9`

A SYN packet was expected but not received.

### `InetDiscardRst:10`

The packet is an invalid RST segment.

### `InetDiscardSynRcvdSyn:11`

A TCP connection in SYN_RCVD state received another SYN segment.

### `InetDiscardSimultaneousConnect:12`

A TCP connection has encountered the simultaneous-connect condition.

### `InetDiscardPawsFailed:13`

A TCP PAWS check failed.

### `InetDiscardLandAttack:14`

The packet was detected as part of a LAND (Local Area Network Denial) attack,

### `InetDiscardMissedReset:15`

An SYN segment outside the receive window was received on a SYN_RCVD connection. An RST may have been missed.

### `InetDiscardOutsideWindow:16`

A TCP segment was outside the receive window.

### `InetDiscardDuplicateSegment:17`

A duplicate TCP segment was received.

### `InetDiscardClosedWindow:18`

The TCP receive window was closed.

### `InetDiscardTcbRemoved:19`

The TCP connection was closed.

### `InetDiscardFinWait2:20`

The TCP connection is closing.

### `InetDiscardReassemblyConflict:21`

A TCP data reassembly conflict was encountered on reception of a FIN segment.

### `InetDiscardFinReceived:22`

A FIN was already received on a TCP connection; no more data can be received.

### `InetDiscardListenerInvalidFlags:23`

A segment with invalid flags was received by a listening TCP socket.

### `InetDiscardUrgentDeliveryAllocationFailure:24`

There is insufficient memory for URG delivery on a TCP connection.

### `InetDiscardTcbNotInTcbTable:25`

A TCP connection was closed due to urgent delivery.

### `InetDiscardTimeWaitTcbReceivedRstOutsideWindow:26`

A **TIME_WAIT** state TCP connection received a RST segment outside the window.

### `InetDiscardTimeWaitTcbSynAndOtherFlags:27`

A **TIME_WAIT** state TCP connection received a segment with SYN and one or more incompatible flags.

### `InetDiscardTimeWaitTcb:28`

A **TIME_WAIT** state TCP connection received an invalid segment.

### `InetDiscardSynAckWithFastopenCookieRequest:29`

The packet, a SYN-ACK containing a request for a Fast Open cookie, was discarded.

### `InetDiscardPauseAccept:30`

This indicates the packet was discarded due to a pause in acceptance.

### `InetDiscardSynAttack:31`

The packet was discarded as part of mitigating a SYN flood attack.

### `InetDiscardAcceptInspection:32`

The packet was discarded during the acceptance inspection process.

### `InetDiscardAcceptRedirection:33`

The packet was discarded because it was subject to acceptance redirection.

### `InetDiscardReasonMaxEnumValue`

The maximum value for enumeration.

## Remarks

## See also