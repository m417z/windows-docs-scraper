# TCP_ESTATS_PATH_ROD_v0 structure

## Description

The **TCP_ESTATS_PATH_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on network path measurement for a TCP connection.

## Members

### `FastRetran`

Type: **ULONG**

The number of invocations of the Fast Retransmit algorithm.

### `Timeouts`

Type: **ULONG**

The number of times the retransmit timeout has expired when
the retransmission timer backoff multiplier is equal to one.

### `SubsequentTimeouts`

Type: **ULONG**

The number of times the retransmit timeout has expired after
the retransmission timer has been doubled.

For more information, see section 5.5 of RFC 2988 discussed in the Remarks below.

### `CurTimeoutCount`

Type: **ULONG**

The current number of times the retransmit timeout has
expired without receiving an acknowledgment for new data.

The **CurTimeoutCount** member is reset to zero when new
data is acknowledged and incremented for each invocation of
Section 5.5 of RFC 2988.

### `AbruptTimeouts`

Type: **ULONG**

The number of timeouts that occurred without any
immediately preceding duplicate acknowledgments or other
indications of congestion. Abrupt timeouts indicate that
the path lost an entire window of data or acknowledgments.

Timeouts that are preceded by duplicate acknowledgments or
other congestion signals (Explicit Congestion Notification, for example) are not counted as
abrupt, and might have been avoided by a more sophisticated
Fast Retransmit algorithm.

### `PktsRetrans`

Type: **ULONG**

The number of segments transmitted containing at least some
retransmitted data.

### `BytesRetrans`

Type: **ULONG**

The number of bytes retransmitted.

### `DupAcksIn`

Type: **ULONG**

The number of duplicate ACKs received.

### `SacksRcvd`

Type: **ULONG**

The number of Selective Acknowledgment (SACK) options received.

### `SackBlocksRcvd`

Type: **ULONG**

The number of SACK blocks received (within SACK options).

### `CongSignals`

Type: **ULONG**

The number of multiplicative downward congestion window
adjustments due to all forms of congestion signals,
including Fast Retransmit, Explicit Congestion Notification
(ECN), and timeouts. This member summarizes all events that
invoke the Multiplicative Decrease (MD) portion of Additive Increase Multiplicative
Decrease (AIMD) congestion control, and as such is the best
indicator of how a congestion windows is being affected by congestion.

Note that retransmission timeouts multiplicatively reduce
the window implicitly by setting the slow start threshold size, and are
included in the value stored in the **CongSignals** member. In order to minimize
spurious congestion indications due to out-of-order
segments, the **CongSignals** member is incremented in
association with the Fast Retransmit algorithm.

### `PreCongSumCwnd`

Type: **ULONG**

The sum of the values of the congestion window, in bytes,
captured each time a congestion signal is received.

This
member is updated each time the **CongSignals** member is
incremented, such that the change in
the **PreCongSumCwnd** member divided by the change in
the **CongSignals** member is the average window (over some
interval) just prior to a congestion signal.

### `PreCongSumRtt`

Type: **ULONG**

The sum, in milliseconds, of the last sample of the network round-trip-time (RTT) prior to the received congestion signals. The last sample of the RTT is stored in the **SampleRtt** member.

The **PreCongSumRtt** member
is updated each time the **CongSignals** member is incremented,
such that the change in the **PreCongSumRtt** divided by
the change in the **CongSignals** member is the average RTT
(over some interval) just prior to a congestion signal.

### `PostCongSumRtt`

Type: **ULONG**

The sum, in milliseconds, of the first sample of the network RTT (stored in the **SampleRtt** member)
following each congestion signal.

The change in
the **PostCongSumRtt** member divided by the change in
the **PostCongCountRtt** member is the average RTT (over some
interval) just after a congestion signal.

### `PostCongCountRtt`

Type: **ULONG**

The number of RTT samples, in bytes, included in
the **PostCongSumRtt** member.

The change in
the **PostCongSumRtt** member divided by the change in
the **PostCongCountRtt** member is the average RTT (over some
interval) just after a congestion signal.

### `EcnSignals`

Type: **ULONG**

The number of congestion signals delivered to the TCP
sender via ECN.

This is
typically the number of segments bearing Echo Congestion

Experienced (ECE) bits, but
also includes segments failing the ECN nonce check or
other explicit congestion signals.

### `EceRcvd`

Type: **ULONG**

The number of segments received with IP headers bearing
Congestion Experienced (CE) markings.

### `SendStall`

Type: **ULONG**

The number of interface stalls or other sender local
resource limitations that are treated as congestion
signals.

### `QuenchRcvd`

Type: **ULONG**

Reserved for future use. This member is always set to zero.

### `RetranThresh`

Type: **ULONG**

The number of duplicate acknowledgments required to trigger
Fast Retransmit.

Note that although this is constant in
traditional Reno TCP implementations, it is adaptive in
many newer TCP implementations.

### `SndDupAckEpisodes`

Type: **ULONG**

The number of Duplicate Acks Sent when prior Ack was not
duplicate. This is the number of times that a contiguous
series of duplicate acknowledgments have been sent.

This is an indication of the number of data segments lost
or reordered on the path from the remote TCP endpoint to
the near TCP endpoint.

### `SumBytesReordered`

Type: **ULONG**

The sum of the amounts SND.UNA advances on the
acknowledgment which ends a dup-ack episode without a
retransmission.

Note the change in the **SumBytesReordered** member divided
by the change in the **NonRecovDaEpisodes** member is an
estimate of the average reordering distance, over some
interval.

### `NonRecovDa`

Type: **ULONG**

The number of duplicate acks (or SACKS) that did not trigger a Fast
Retransmit because ACK advanced prior to the number of
duplicate acknowledgments reaching the **RetranThresh**.

Note that the change in the **NonRecovDa** member divided by
the change in the **NonRecovDaEpisodes** member is an
estimate of the average reordering distance in segments
over some interval.

### `NonRecovDaEpisodes`

Type: **ULONG**

The number of duplicate acknowledgment episodes that did
not trigger a Fast Retransmit because ACK advanced prior to
the number of duplicate acknowledgments reaching
the **RetranThresh**.

### `AckAfterFr`

Type: **ULONG**

Reserved for future use. This member is always set to zero.

### `DsackDups`

Type: **ULONG**

The number of duplicate segments reported to the local host
by D-SACK blocks.

### `SampleRtt`

Type: **ULONG**

The most recent raw network round trip time measurement, in milliseconds, used in
calculation of the retransmission timer (RTO).

### `SmoothedRtt`

Type: **ULONG**

The smoothed round trip time, in milliseconds, used in calculation of the
RTO.

### `RttVar`

Type: **ULONG**

The round trip time variation, in milliseconds, used in calculation of the
RTO.

### `MaxRtt`

Type: **ULONG**

The maximum sampled round trip time in milliseconds.

### `MinRtt`

Type: **ULONG**

The minimum sampled round trip time in milliseconds.

### `SumRtt`

Type: **ULONG**

The sum of all sampled round trip times in milliseconds.

Note that the change in the **SumRtt** member divided by the
change in the **CountRtt** member is the mean RTT, uniformly
averaged over an enter interval.

### `CountRtt`

Type: **ULONG**

The number of round trip time samples included in
the **SumRtt** member.

### `CurRto`

Type: **ULONG**

The current value, in milliseconds, of the retransmit timer.

### `MaxRto`

Type: **ULONG**

The maximum value, in milliseconds, of the retransmit timer.

### `MinRto`

Type: **ULONG**

The minimum value, in milliseconds, of the retransmit timer.

### `CurMss`

Type: **ULONG**

The current maximum segment size (MSS), in bytes.

### `MaxMss`

Type: **ULONG**

The maximum MSS, in bytes.

### `MinMss`

Type: **ULONG**

The minimum MSS, in bytes.

### `SpuriousRtoDetections`

Type: **ULONG**

The number of acknowledgments reporting segments that have
already been retransmitted due to a Retransmission Timeout.

## Remarks

The **TCP_ESTATS_PATH_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_PATH_ROD_v0** is defined as version 0 of the structure for read-only dynamic information on network path measurement for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_PATH_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsPath** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The path MTU discovery and maximum segment size are discussed in detail in the IETF RFC 1191 on Path MTU discovery. For more information, see [http://www.ietf.org/rfc/rfc1191.txt](http://tools.ietf.org/html/rfc1191).

TCP congestion control and congestion control algorithms are discussed in detail in the IETF RFC 2581 on TCP Congestion Control. For more information, see [http://www.ietf.org/rfc/rfc2581.txt](http://tools.ietf.org/html/rfc2581).

SACK and an extension to the SACK option are discussed in detail in the IETF RFC 2883 on An Extension to the Selective Acknowledgment
(SACK) Option for TCP. For more information, see [http://www.ietf.org/rfc/rfc2883.txt](http://tools.ietf.org/html/rfc2883).

The TCP retransmission timer (RTO) and the smoothed round-trip-time (RTT) are discussed in detail in the IETF RFC 2988 on Computing TCP's Retransmission Timer. For more information, see [http://www.ietf.org/rfc/rfc2988.txt](http://tools.ietf.org/html/rfc2988).

Explicit Congestion Notification in IP is discussed in detail in the IETF RFC 2581 on The Addition of Explicit Congestion Notification
(ECN) to IP. For more information, see [http://www.ietf.org/rfc/rfc3168.txt](http://tools.ietf.org/html/rfc3168).

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_PATH_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **FastRetran** | tcpEStatsStackFastRetran |
| **Timeouts** | tcpEStatsPerfTimeouts |
| **SubsequentTimeouts** | tcpEStatsStackSubsequentTimeouts |
| **CurTimeoutCount** | tcpEStatsStackCurTimeoutCount |
| **AbruptTimeouts** | tcpEStatsStackAbruptTimeouts |
| **PktsRetrans** | tcpEStatsPerfSegsRetrans |
| **BytesRetrans** | tcpEStatsPerfOctetsRetrans |
| **DupAcksIn** | tcpEStatsStackDupAcksIn |
| **SacksRcvd** | tcpEStatsStackSACKsRcvd |
| **SackBlocksRcvd** | tcpEStatsStackSACKBlocksRcvd |
| **CongSignals** | tcpEStatsPerfCongSignals |
| **PreCongSumCwnd** | tcpEStatsPathPreCongSumCwnd |
| **PreCongSumRtt** | tcpEStatsPathPreCongSumRTT |
| **PostCongSumRtt** | tcpEStatsPathPostCongSumRTT |
| **PostCongCountRtt** | tcpEStatsPathPostCongCountRTT |
| **EcnSignals** | tcpEStatsPathECNsignals |
| **EceRcvd** | tcpEStatsPathCERcvd |
| **SendStall** | tcpEStatsStackSendStall |
| **QuenchRcvd** | No mapping to this member. |
| **RetranThresh** | tcpEStatsPathRetranThresh |
| **SndDupAckEpisodes** | tcpEStatsPathDupAckEpisodes |
| **SumBytesReordered** | tcpEStatsPathSumOctetsReordered |
| **NonRecovDa** | tcpEStatsPathNonRecovDA |
| **NonRecovDaEpisodes** | tcpEStatsPathNonRecovDAEpisodes |
| **AckAfterFr** | No mapping to this member. |
| **DsackDups** | tcpEStatsStackDSACKDups |
| **SampleRtt** | tcpEStatsPathSampleRTT |
| **SmoothedRtt** | tcpEStatsPerfSmoothedRTT |
| **RttVar** | tcpEStatsPathRTTVar |
| **MaxRtt** | tcpEStatsPathMaxRTT |
| **MinRtt** | tcpEStatsPathMinRTT |
| **SumRtt** | tcpEStatsPathSumRTT |
| **CountRtt** | tcpEStatsPathCountRTT |
| **CurRto** | tcpEStatsPerfCurRTO |
| **MaxRto** | tcpEStatsPathMaxRTO |
| **MinRto** | tcpEStatsPathMinRTO |
| **CurMss** | tcpEStatsPerfCurMSS |
| **MaxMss** | tcpEStatsStackMaxMSS |
| **MinMss** | tcpEStatsStackMinMSS |
| **SpuriousRtoDetections** | tcpEStatsStackSpuriousRtoDetected |

The [TCP_ESTATS_FINE_RTT_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rod_v0) structure has members that provide similar data to the **RttVar**, **MaxRtt**, **MinRtt**, and **SumRtt** members of the **TCP_ESTATS_PATH_ROD_v0** structure. However, the time is reported in microseconds for the similar members of the **TCP_ESTATS_FINE_RTT_ROD_v0** structure.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_FINE_RTT_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_fine_rtt_rod_v0)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)