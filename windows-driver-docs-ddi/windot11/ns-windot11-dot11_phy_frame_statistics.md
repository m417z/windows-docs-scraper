# DOT11_PHY_FRAME_STATISTICS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_PHY_FRAME_STATISTICS structure records statistical counters for the IEEE physical (PHY)
layer of the 802.11 station.

## Members

### `ullTransmittedFrameCount`

The number of MSDU packets and MMPDU frames that the IEEE PHY layer of the 802.11 station has
successfully transmitted.

### `ullMulticastTransmittedFrameCount`

The number of multicast or broadcast MSDU packets and MMPDU frames that the IEEE PHY layer of the
802.11 station has successfully transmitted.

### `ullFailedCount`

The number of MSDU packets and MMPDU frames that the 802.11 station failed to transmit after
exceeding the retry limits defined by the 802.11 IEEE
**dot11ShortRetryLimit** or
**dot11LongRetryLimit** MIB counters. For more information about these MIB counters, see
[OID_DOT11_SHORT_RETRY_LIMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-short-retry-limit) or
[OID_DOT11_LONG_RETRY_LIMIT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-long-retry-limit).

### `ullRetryCount`

The number of MSDU packets and MMPDU frames that the 802.11 station successfully transmitted after
one or more attempts.

### `ullMultipleRetryCount`

The number of MSDU packets and MMPDU frames that the 802.11 station successfully transmitted after
more than one retransmission attempt.

For MSDU packets, the miniport driver must increment this counter for each packet that was
transmitted successfully after one or more of its MPDU fragments required retransmission.

### `ullMaxTXLifetimeExceededCount`

The number of MSDU packets and MMPDU frames that the 802.11 station failed to transmit because of
a timeout as defined by the IEEE 802.11
**dot11MaxTransmitMSDULifetime** MIB object. For more information about this MIB object, see
[OID_DOT11_MAX_TRANSMIT_MSDU_LIFETIME](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-max-transmit-msdu-lifetime).

### `ullTransmittedFragmentCount`

The number of MPDU frames that the 802.11 station transmitted and acknowledged through a received
802.11 ACK frame.

### `ullRTSSuccessCount`

The number of times that the 802.11 station received a Clear To Send (CTS) frame in response to a
Request To Send (RTS) frame.

### `ullRTSFailureCount`

The number of times that the 802.11 station did not receive a CTS frame in response to an RTS
frame.

### `ullACKFailureCount`

The number of times that the 802.11 station expected and did not receive an Acknowledgement (ACK)
frame.

### `ullReceivedFrameCount`

The total number of MSDU packets and MMPDU frames that the 802.11 station has successfully
received.

For MSDU packets, the miniport driver must increment this counter for each packet whose MPDU
fragments were received and passed frame check sequence (FCS) verification and replay detection. The
miniport driver must increment this member regardless of whether the received MSDU packet or MPDU
fragment fail MAC-layer cipher decryption.

This counter is optional. If the NIC does not support this counter, the miniport driver should set
this member to DOT11_STATISTICS_UNKNOWN.

### `ullMulticastReceivedFrameCount`

The number of multicast or broadcast MSDU packets and MMPDU frames that the 802.11 station has
successfully received.

For MSDU packets, the miniport driver must increment this counter for each packet whose MPDU
fragments were received and passed FCS verification and replay detection. The miniport driver must
increment this member regardless of whether the received MSDU packet or MPDU fragment fail MAC-layer
cipher decryption.

This counter is optional. If the NIC does not support this counter, the miniport driver should set
this member to DOT11_STATISTICS_UNKNOWN.

### `ullPromiscuousReceivedFrameCount`

The number of MSDU packets or MMPDU frames received by the 802.11 station when a promiscuous
packet filter is enabled. For more information about packet filters, see
[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter).

If a promiscuous packet filter is enabled, the miniport driver must only increment this counter for
received MSDU packets or MMPDU frames that would have been rejected if the filter was not enabled. The
driver must not increment this counter for:

* Unicast MSDU packets or MMPDU frames with a destination MAC address that matches the 802.11
  station's MAC address.
* Multicast or broadcast MSDU packets or MMPDU frames with a destination MAC address that matches an
  entry in the multicast address list of the 802.11 station. For more information about the multicast
  address list, see
  [OID_DOT11_MULTICAST_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-multicast-list).

### `ullMaxRXLifetimeExceededCount`

The number if MSDU packets and MMPDU frames that the 802.11 station discarded because of a timeout
as defined by the IEEE 802.11
**dot11MaxReceiveLifetime** MIB object. For more information about this MIB object, see
[OID_DOT11_MAX_RECEIVE_LIFETIME](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-max-receive-lifetime).

### `ullFrameDuplicateCount`

The number of duplicate MPDU frames that the 802.11 station received. The 802.11 station
determines duplicate frames through the Sequence Control field of the 802.11 MAC header.

### `ullReceivedFragmentCount`

The number of MPDU frames received by the 802.11 station for MSDU packets or MMPDU frames.

### `ullPromiscuousReceivedFragmentCount`

The number of MPDU frames received by the 802.11 station for MSDU packets or MMPDU frames when a
promiscuous packet filter was enabled. For more information about packet filters, see
[OID_GEN_CURRENT_PACKET_FILTER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-packet-filter).

If a promiscuous packet filter is enabled, the miniport driver must only increment this counter for
received MPDU frames that would have been rejected if the filter was not enabled. The driver must not
increment this counter for:

* Unicast MPDU frames with a destination MAC address that matches the 802.11 station's MAC
  address.
* Multicast or broadcast MPDU frames with a destination MAC address that matches an entry in the
  multicast address list of the 802.11 station. For more information about the multicast address list,
  see
  [OID_DOT11_MULTICAST_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-multicast-list).

### `ullFCSErrorCount`

The number of MPDU frames that the 802.11 station received with FCS errors.

## Syntax

```cpp
typedef struct DOT11_PHY_FRAME_STATISTICS {
  ULONGLONG ullTransmittedFrameCount;
  ULONGLONG ullMulticastTransmittedFrameCount;
  ULONGLONG ullFailedCount;
  ULONGLONG ullRetryCount;
  ULONGLONG ullMultipleRetryCount;
  ULONGLONG ullMaxTXLifetimeExceededCount;
  ULONGLONG ullTransmittedFragmentCount;
  ULONGLONG ullRTSSuccessCount;
  ULONGLONG ullRTSFailureCount;
  ULONGLONG ullACKFailureCount;
  ULONGLONG ullReceivedFrameCount;
  ULONGLONG ullMulticastReceivedFrameCount;
  ULONGLONG ullPromiscuousReceivedFrameCount;
  ULONGLONG ullMaxRXLifetimeExceededCount;
  ULONGLONG ullFrameDuplicateCount;
  ULONGLONG ullReceivedFragmentCount;
  ULONGLONG ullPromiscuousReceivedFragmentCount;
  ULONGLONG ullFCSErrorCount;
} DOT11_PHY_FRAME_STATISTICS, *PDOT11_PHY_FRAME_STATISTICS;
```

## Remarks

The members of this structure are used to record PHY-level statistics for:

* 802.11 MSDU packets.
* 802.11 MMPDU frames.
* 802.11 MPDU frames. MPDU frame counters must include all MPDU fragments sent for an MSDU packet or
  MMPDU frame

## See also

[Extensible Station PHY
Statistics](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-phy-statistics)

[OID_DOT11_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-statistics)

[DOT11_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_statistics)

[Native 802.11 Statistics](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-statistics)