# TCP_ESTATS_SND_CONG_ROD_v0 structure

## Description

The **TCP_ESTATS_SND_CONG_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on sender congestion related data for a TCP connection.

## Members

### `SndLimTransRwin`

Type: **ULONG**

The number of transitions into the "Receiver Limited" state
from either the "Congestion Limited" or "Sender Limited"
states. This state is entered whenever TCP transmission
stops because the sender has filled the announced receiver
window.

### `SndLimTimeRwin`

Type: **ULONG**

The cumulative time, in milliseconds, spent in the "Receiver Limited" state where TCP transmission
stops because the sender has filled the announced receiver
window.

### `SndLimBytesRwin`

Type: **SIZE_T**

The total number of bytes sent in the "Receiver Limited" state.

### `SndLimTransCwnd`

Type: **ULONG**

The number of transitions into the "Congestion Limited"
state from either the "Receiver Limited" or "Sender
Limited" states. This state is entered whenever TCP
transmission stops because the sender has reached some
limit defined by TCP congestion control (the congestion window, for example) or other
algorithms (retransmission timeouts) designed to control
network traffic.

### `SndLimTimeCwnd`

Type: **ULONG**

The cumulative time, in milliseconds, spent in the "Congestion Limited"
state. When there is a
retransmission timeout, it is counted in
this member and not the cumulative time
for some other state.

### `SndLimBytesCwnd`

Type: **SIZE_T**

The total number of bytes sent in the "Congestion Limited" state.

### `SndLimTransSnd`

Type: **ULONG**

The number of transitions into the "Sender Limited" state
from either the "Receiver Limited" or "Congestion Limited"
states. This state is entered whenever TCP transmission
stops due to some sender limit such as running out of
application data or other resources and the Karn algorithm.
When TCP stops sending data for any reason, which cannot be
classified as "Receiver Limited" or "Congestion Limited", it
is treated as "Sender Limited".

### `SndLimTimeSnd`

Type: **ULONG**

The cumulative time, in milliseconds, spent in the "Sender Limited" state.

### `SndLimBytesSnd`

Type: **SIZE_T**

The total number of bytes sent in the "Sender Limited" state.

### `SlowStart`

Type: **ULONG**

The number of times the congestion window has been
increased by the "Slow Start" algorithm.

### `CongAvoid`

Type: **ULONG**

The number of times the congestion window has been
increased by the "Congestion Avoidance" algorithm.

### `OtherReductions`

Type: **ULONG**

The number of congestion window reductions made as a result
of anything other than congestion control algorithms other than "Slow Start" and "Congestion Avoidance" algorithms.

### `CurCwnd`

Type: **ULONG**

The size, in bytes, of the current congestion window.

### `MaxSsCwnd`

Type: **ULONG**

The maximum size, in bytes, of the congestion window size used during "Slow Start."

### `MaxCaCwnd`

Type: **ULONG**

The maximum size, in bytes, of the congestion window used during "Congestion
Avoidance."

### `CurSsthresh`

Type: **ULONG**

The current size, in bytes, of the slow start threshold.

### `MaxSsthresh`

Type: **ULONG**

The maximum size, in bytes, of the slow start threshold, excluding the initial
value.

### `MinSsthresh`

Type: **ULONG**

The minimum size, in bytes, of the slow start threshold.

## Remarks

The **TCP_ESTATS_SND_CONG_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_SND_CONG_ROD_v0** is defined as version 0 of the structure for read-only dynamic information on sender congestion related data for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_SND_CONG_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsSndCong** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

TCP congestion control and congestion control algorithms are discussed in detail in the IETF RFC on TCP Congestion Control. For more information, see [http://www.ietf.org/rfc/rfc2581.txt](http://tools.ietf.org/html/rfc2581).

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_SND_CONG_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **SndLimTransRwin** | tcpEStatsPerfSndLimTransRwin |
| **SndLimTimeRwin** | tcpEStatsPerfSndLimTimeRwin |
| **SndLimBytesRwin** | No mapping to this member. |
| **SndLimTransCwnd** | tcpEStatsPerfSndLimTransCwnd |
| **SndLimTimeCwnd** | tcpEStatsPerfSndLimTimeCwnd |
| **SndLimBytesCwnd** | No mapping to this member. |
| **SndLimTransSnd** | tcpEStatsPerfSndLimTransSnd |
| **SndLimTimeSnd** | tcpEStatsPerfSndLimTimeSnd |
| **SndLimBytesSnd** | No mapping to this member. |
| **SlowStart** | tcpEStatsStackSlowStart |
| **CongAvoid** | tcpEStatsStackCongAvoid |
| **OtherReductions** | tcpEStatsStackOtherReductions |
| **CurCwnd** | tcpEStatsPerfCurCwnd |
| **MaxSsCwnd** | tcpEStatsStackMaxSsCwnd |
| **MaxCaCwnd** | tcpEStatsStackMaxCaCwnd |
| **CurSsthresh** | tcpEStatsPerfCurSsthresh |
| **MaxSsthresh** | tcpEStatsStackMaxSsthresh |
| **MinSsthresh** | tcpEStatsStackMinSsthresh |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)