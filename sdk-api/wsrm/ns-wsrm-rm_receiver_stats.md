# RM_RECEIVER_STATS structure

## Description

The **RM_RECEIVER_STATS** structure provides statistical information for a Reliable Multicast receiver session. This structure is used with the [RM_RECEIVER_STATISTICS](https://learn.microsoft.com/windows/desktop/WinSock/socket-options) socket option.

## Members

### `NumODataPacketsReceived`

Type: **ULONGULONG**

The number of original data (ODATA) sequences received.

### `NumRDataPacketsReceived`

Type: **ULONGULONG**

The number of repair data (RDATA) sequences received.

### `NumDuplicateDataPackets`

Type: **ULONGULONG**

The number of duplicate sequences received.

### `DataBytesReceived`

Type: **ULONGULONG**

The number of data bytes received.

### `TotalBytesReceived`

Type: **ULONGULONG**

The total bytes received, consisting of source path message (SPM), original data (ODATA) and repair data (RDATA) sequences.

### `RateKBitsPerSecOverall`

Type: **ULONGULONG**

An internally calculated receive rate from the beginning of the session, in kilobits per second.

### `RateKBitsPerSecLast`

Type: **ULONGULONG**

The receive rate for the period specified by INTERNAL_RATE_CALCULATION_FREQUENCY.

### `TrailingEdgeSeqId`

Type: **ULONGULONG**

The oldest sequence identifier in the receive window.

### `LeadingEdgeSeqId`

Type: **ULONGULONG**

The newest sequence identifier in the receive window.

### `AverageSequencesInWindow`

Type: **ULONGULONG**

The average number of sequences in the receive window.

### `MinSequencesInWindow`

Type: **ULONGULONG**

The minimum number of sequences in the receive window.

### `MaxSequencesInWindow`

Type: **ULONGULONG**

The maximum number of sequences in the receive window.

### `FirstNakSequenceNumber`

Type: **ULONGULONG**

The sequence number for the first outstanding negative acknowledgment (NAK).

### `NumPendingNaks`

Type: **ULONGULONG**

The number of sequences awaiting a NAK confirmation.

### `NumOutstandingNaks`

Type: **ULONGULONG**

The number of sequences awaiting repair data (RDATA).

### `NumDataPacketsBuffered`

Type: **ULONGULONG**

The number of packets currently buffered.

### `TotalSelectiveNaksSent`

Type: **ULONGULONG**

The number of selective NAKs sent this session.

### `TotalParityNaksSent`

Type: **ULONGULONG**

The number of parity NAKs sent this session.

## See also

[RM_SENDER_STATS](https://learn.microsoft.com/windows/desktop/api/wsrm/ns-wsrm-rm_sender_stats)

[Reliable Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-)

[Socket
Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)