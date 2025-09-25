# NetAdapterReportWakeReasonPacket function

## Description

The **NetAdapterReportWakeReasonPacket** function reports to the framework that a net adapter generated a wake-up event because it received a packet that matched a wake-on-LAN (WoL) pattern.

## Parameters

### `Adapter` [_In_]

A handle to the NETADAPTER object.

### `Reason` [_In_]

A pointer to the [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure that represents the wake reason packet that the net adapter received.

## Remarks

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet)