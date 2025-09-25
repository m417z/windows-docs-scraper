# TCP_ESTATS_DATA_ROD_v0 structure

## Description

The **TCP_ESTATS_DATA_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on data transfer for a TCP connection.

## Members

### `DataBytesOut`

Type: **ULONG64**

The number of octets of data contained in transmitted
segments, including retransmitted data. Note that this does
not include TCP headers.

### `DataSegsOut`

Type: **ULONG64**

The number of segments sent containing a positive length
data segment.

### `DataBytesIn`

Type: **ULONG64**

The number of octets contained in received data segments,
including retransmitted data. Note that this does not
include TCP headers.

### `DataSegsIn`

Type: **ULONG64**

The number of segments received containing a positive
length data segment.

### `SegsOut`

Type: **ULONG64**

The total number of segments sent.

### `SegsIn`

Type:

The total number of segments received.

### `SoftErrors`

Type: **ULONG**

The number of segments that fail various consistency tests
during TCP input processing. Soft errors might cause the
segment to be discarded but some do not. Some of these soft
errors cause the generation of a TCP acknowledgment, while
others are silently discarded.

### `SoftErrorReason`

Type: **ULONG**

A value that identifies which consistency test most recently
failed during TCP input processing. This object is set every time the **SoftErrors** member is incremented.

### `SndUna`

Type: **ULONG**

The value of the oldest unacknowledged sequence
number. Note that this member is a TCP state variable.

### `SndNxt`

Type: **ULONG**

The next sequence number to be sent.
Note that this member is not monotonic (and thus not
a counter), because TCP sometimes retransmits lost data by
pulling the member back to the missing data.

### `SndMax`

Type: **ULONG**

The farthest forward (right most or largest) sequence number to be sent.
Note that this will be equal to the **SndNxt** member except
when the **SndNxt** member is pulled back during recovery.

### `ThruBytesAcked`

Type: **ULONG64**

The number of octets for which cumulative acknowledgments
have been received. Note that this will be the sum of
changes to the **SndNxt** member.

### `RcvNxt`

Type: **ULONG**

The next sequence number to be received.
Note that this member is not monotonic (and thus not
a counter), because TCP sometimes retransmits lost data by
pulling the member back to the missing data.

### `ThruBytesReceived`

Type: **ULONG64**

The number of octets for which cumulative acknowledgments
have been sent. Note that this will be the sum of changes
to the **RcvNxt** member.

## Remarks

The **TCP_ESTATS_DATA_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_DATA_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on data transfer for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_DATA_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsData** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_DATA_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **DataBytesOut** | tcpEStatsPerfDataOctetsOut |
| **DataSegsOut** | tcpEStatsPerfDataSegsOut |
| **DataBytesIn** | tcpEStatsPerfDataOctetsIn |
| **DataSegsIn** | tcpEStatsPerfDataSegsIn |
| **SegsOut** | tcpEStatsPerfSegsOut |
| **SegsIn** | tcpEStatsPerfSegsIn |
| **SoftErrors** | tcpEStatsStackSoftErrors |
| **SoftErrorReason** | tcpEStatsStackSoftErrorReason |
| **SndUna** | tcpEStatsAppSndUna |
| **SndNxt** | tcpEStatsAppSndNxt |
| **SndMax** | tcpEStatsAppSndMax |
| **ThruBytesAcked** | tcpEStatsAppThruOctetsAcked |
| **RcvNxt** | tcpEStatsAppRcvNxt |
| **ThruBytesReceived** | tcpEStatsAppThruOctetsReceived |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)