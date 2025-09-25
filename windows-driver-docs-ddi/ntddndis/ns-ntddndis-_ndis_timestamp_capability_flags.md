# _NDIS_TIMESTAMP_CAPABILITY_FLAGS structure

## Description

The **NDIS_TIMESTAMP_CAPABILITY_FLAGS** structure represents the combined timestamping capabilities of a network interface card (NIC) and miniport driver in various contexts.

## Members

### `PtpV2OverUdpIPv4EventMsgReceiveHw`

A value of **TRUE** indicates that during packet reception the NIC can recognize in hardware a PTP version 2 *event* message contained in an IPv4 UDP packet and generate a timestamp in hardware corresponding to when such a packet was received. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv4AllMsgReceiveHw`

A value of **TRUE** indicates that during packet reception the NIC can recognize in hardware *any* PTP version 2 message (not just PTP event messages) contained in an IPv4 UDP packet and generate a timestamp in hardware corresponding to when such a packet was received. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv4EventMsgTransmitHw`

A value of **TRUE** indicates that during packet transmission the NIC can recognize in hardware a PTP version 2 *event* message contained in an IPv4 UDP packet and generate a timestamp in hardware corresponding to when such a packet was transmitted. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv4AllMsgTransmitHw`

A value of **TRUE** indicates that during packet transmission the NIC can recognize in hardware *any* PTP version 2 message (not just PTP event messages) contained in an IPv4 UDP packet and generate a timestamp in hardware corresponding to when such a packet was transmitted. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv6EventMsgReceiveHw`

A value of **TRUE** indicates that during packet reception the NIC can recognize in hardware a PTP version 2 *event* message contained in an IPv6 UDP packet and generate a timestamp in hardware corresponding to when such a packet was received. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv6AllMsgReceiveHw`

A value of **TRUE** indicates that during packet reception the NIC can recognize in hardware *any* PTP version 2 message (not just PTP event messages) contained in an IPv6 UDP packet and generate a timestamp in hardware corresponding to when such a packet was received. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv6EventMsgTransmitHw`

A value of **TRUE** indicates that during packet transmission the NIC can recognize in hardware a PTP version 2 *event* message contained in an IPv6 UDP packet and generate a timestamp in hardware corresponding to when such a packet was transmitted. A value of **FALSE** indicates the hardware is not capable of this.

### `PtpV2OverUdpIPv6AllMsgTransmitHw`

A value of **TRUE** indicates that during packet transmission the NIC can recognize in hardware *any* PTP version 2 message (not just PTP event messages) contained in an IPv6 UDP packet and generate a timestamp in hardware corresponding to when such a packet was transmitted. A value of **FALSE** indicates the hardware is not capable of this

### `AllReceiveHw`

A value of **TRUE** indicates that the NIC can generate a hardware timestamp for all received packets (for example, not just PTP). A value of **FALSE** indicates the NIC doesn't have this capability.

### `AllTransmitHw`

A value of **TRUE** indicates that the NIC can generate a hardware timestamp for all transmitted packets (for example, not just PTP). A value of **FALSE** indicates the NIC doesn't have this capability.

### `TaggedTransmitHw`

A value of **TRUE** indicates that the NIC can generate a hardware timestamp for any specific transmitted packet when indicated to do so by the operating system. The operating system will indicate this to the miniport/hardware using a metadata field in the packet. For more details, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets). A value of **FALSE** indicates the NIC doesn't have this capability.

### `AllReceiveSw`

A value of **TRUE** indicates that the miniport driver can generate a software timestamp for all received packets. The driver should generate the timestamp by calling the [**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) API. A value of **FALSE** indicates the NIC doesn't have this capability.

### `AllTransmitSw`

A value of **TRUE** indicates that the miniport driver can generate a software timestamp for all transmitted packets. The timestamp should be generated in software using [**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) just before the packet is transmitted. A value of **FALSE** indicates the NIC doesn't have this capability.

### `TaggedTransmitSw`

A value of **TRUE** indicates that the miniport driver can generate a software timestamp for any specific transmitted packet when indicated to do so by the operating system. The operating system will indicate this to the miniport using a metadata field in the packet. For more details, see [Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets). The miniport driver should generate the timestamp using [**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) just before the packet is transmitted. A value of **FALSE** indicates the NIC doesn't have this capability.

## Remarks

The **NDIS_TIMESTAMP_CAPABILITY_FLAGS** structure is a field in the [**NDIS_TIMESTAMP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_timestamp_capabilities) structure.

## See also

[**NDIS_TIMESTAMP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_timestamp_capabilities)

[**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[Reporting timestamping capabilities and current configuration](https://learn.microsoft.com/windows-hardware/drivers/network/reporting-timestamping-capabilities)

[Attaching timestamps to packets](https://learn.microsoft.com/windows-hardware/drivers/network/attaching-timestamps-to-packets)