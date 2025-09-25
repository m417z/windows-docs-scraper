# TCP_SOFT_ERROR enumeration

## Description

The **TCP_SOFT_ERROR** enumeration defines the reason for non-fatal or soft errors recorded on a TCP connection.

## Constants

### `TcpErrorNone:0`

No soft errors have occurred.

### `TcpErrorBelowDataWindow`

All data in the segment is below
the send unacknowledged (SND.UNA) sequence number. This soft error is normal for keep-alives and zero window probes.

### `TcpErrorAboveDataWindow`

Some data in the segment is above
send window (SND.WND) size. This soft error indicates an implementation bug or possible
attack.

### `TcpErrorBelowAckWindow`

An ACK was received below the SND.UNA sequence number. This soft error indicates that the
return path is reordering ACKs.

### `TcpErrorAboveAckWindow`

An ACK was received for data that we have not sent.
This soft error indicates an implementation bug or possible attack.

### `TcpErrorBelowTsWindow`

The Timestamp Echo Reply (TSecr) on the segment is older than the
current TS.Recent (a timestamp to be echoed in TSecr whenever a
segment is sent). This error is applicable to TCP connections that use the TCP Timestamps option (TSopt) defined by the IETF in RFC 1323. For more information, see [http://www.ietf.org/rfc/rfc1323.txt](https://www.ietf.org/rfc/rfc1323.txt). This soft error is normal for the rare case where the Protect Against Wrapped
Sequences numbers (PAWS)
mechanism detects data reordered by the network.

### `TcpErrorAboveTsWindow`

The TSecr on the segment is newer than the
current TS.Recent. This soft error indicates an implementation bug or
possible attack.

### `TcpErrorDataChecksumError`

An incorrect TCP checksum was received. Note that this value
is intrinsically fragile, because the header fields used to
identify the connection may have been corrupted.

### `TcpErrorDataLengthError`

A data length error occurred.

This value is not defined in the IETF draft RFC on the TCP Extended Statistics MIB.

### `TcpErrorMaxSoftError`

The maximum possible value for the [TCP_SOFT_ERROR](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_soft_error)_STATE enumeration type. This is not a legal value for the reason for a soft error for a TCP connection.

## Remarks

The **TCP_SOFT_ERROR** enumeration is defined on Windows Vista and later.

The values in this enumeration are defined in the IETF draft RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)