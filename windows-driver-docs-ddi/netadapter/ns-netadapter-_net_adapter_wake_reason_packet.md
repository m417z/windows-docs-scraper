# NET_ADAPTER_WAKE_REASON_PACKET structure

## Description

The **NET_ADAPTER_WAKE_REASON_PACKET** structure describes a network packet (known as a wake packet) that caused the network adapter to generate a wake-up event.

## Members

### `Size`

The size of this structure, in bytes.

### `PatternId`

A ULONG value that specifies the identifier of the wake-on-LAN (WOL) pattern that matches the wake packet.

### `OriginalPacketSize`

A ULONG value that specifies the original length, in units of bytes, of the wake packet.

### `WakePacket`

A WDFMEMORY buffer that contains the wake packet.

## Remarks

Call [**NET_ADAPTER_WAKE_REASON_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_packet_init) to initialize this structure if the [**NET_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ne-netwakesource-_net_wake_source_type) is NetWakeSourceTypeBitmapPattern.

Call [**NET_ADAPTER_WAKE_REASON_MAGIC_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_magic_packet_init) to initialize this structure if the **NET_WAKE_SOURCE_TYPE** is NetWakeSourceTypeMagicPacket.

Call [**NET_ADAPTER_WAKE_REASON_FILTER_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_filter_packet_init) to initialize this structure if the **NET_WAKE_SOURCE_TYPE** is NetWakeSourceTypePacketFilterMatch.

Call [**NET_ADAPTER_WAKE_REASON_EAPOL_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_eapol_packet_init) to initialize this structure if the **NET_WAKE_SOURCE_TYPE** is NetWakeSourceTypeEapolPacket.

A **NET_ADAPTER_WAKE_REASON_PACKET** structure is passed as an input parameter to [**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_REASON_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_packet_init)

[**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket)