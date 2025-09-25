## Description

The **NET_ADAPTER_WAKE_PATTERN_ID** enumeration specifies the wake pattern ID in the [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure.

## Constants

### `NetAdapterWakeMagicPatternId:0x0000fffe`

### `NetAdapterWakeEapolPatternId:0x0000fffd`

### `NetAdapterWakeFilterPatternId:0x0000fffc`

## Remarks

See [**NET_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ne-netwakesource-_net_wake_source_type) for descriptions of each wake source type.

An initialized [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure is an input to [**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket).

## See also

[**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet)

[**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket)