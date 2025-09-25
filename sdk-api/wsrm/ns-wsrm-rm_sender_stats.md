# RM_SENDER_STATS structure

## Description

The **RM_SENDER_STATS** structure provides statistical information for a Reliable Multicast sender session. This structure is used with the [RM_SENDER_STATISTICS](https://learn.microsoft.com/windows/desktop/WinSock/socket-options) socket option.

## Members

### `DataBytesSent`

Type: **ULONGULONG**

Number of client data bytes sent out.

### `TotalBytesSent`

Type: **ULONGULONG**

Total bytes sent, consisting of source path message (SPM), original data (ODATA) and repair data (RDATA) sequences.

### `NaksReceived`

Type: **ULONGULONG**

Number of NAKs received.

### `NaksReceivedTooLate`

Type: **ULONGULONG**

Number of NAKs received after the send window advanced beyond the NAK'ed sequence.

### `NumOutstandingNaks`

Type: **ULONGULONG**

Number of NAKs for which responses have not been sent.

### `NumNaksAfterRData`

Type: **ULONGULONG**

Number of NAKs after repair data (RDATA) sequences were sent for which responses have not been sent.

### `RepairPacketsSent`

Type: **ULONGULONG**

Number of repair data (RDATA) packets sent.

### `BufferSpaceAvailable`

Type: **ULONGULONG**

Number of partial messages dropped.

### `TrailingEdgeSeqId`

Type: **ULONGULONG**

Oldest sequence identifier in the send window.

### `LeadingEdgeSeqId`

Type: **ULONGULONG**

Newest sequence identifier in the send window.

### `RateKBitsPerSecOverall`

Type: **ULONGULONG**

Internally calculated send rate from the beginning of the session, in kilobits per second.

### `RateKBitsPerSecLast`

Type: **ULONGULONG**

Send rate for the period specified by INTERNAL_RATE_CALCULATION_FREQUENCY.

### `TotalODataPacketsSent`

Type: **ULONGULONG**

Total original data (ODATA) packets sent.

## See also

[RM_RECEIVER_STATS](https://learn.microsoft.com/windows/desktop/api/wsrm/ns-wsrm-rm_receiver_stats)

[Reliable Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-)

[Socket
Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)