## Description

The client driver calls the **NET_ADAPTER_WAKE_REASON_FILTER_PACKET_INIT** function to initialize a [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure when reporting that a packet matching a driver supported filter caused a wake-up event.

## Parameters

### `Reason` [out]

A pointer to a driver allocated [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure.

## Remarks

When the [**NET_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ne-netwakesource-_net_wake_source_type) is
NetWakeSourceTypePacketFilterMatch, call **NET_ADAPTER_WAKE_REASON_FILTER_PACKET_INIT** to initialize the [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure. Call [**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket) to report this wake reason to NetAdapterCx.

This function zeroes out the memory for the **NET_ADAPTER_WAKE_REASON_PACKET** structure, sets the **Size** member, and sets the **PatternId** member to NetAdapterWakeFilterPatternId.

## See also

[Configuring NetAdapterCx Power Management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet)

[**NetAdapterReportWakeReasonPacket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterreportwakereasonpacket)

[**NET_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ne-netwakesource-_net_wake_source_type)