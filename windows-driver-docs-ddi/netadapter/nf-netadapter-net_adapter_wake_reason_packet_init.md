# NET_ADAPTER_WAKE_REASON_PACKET_INIT function

## Description

The **NET_ADAPTER_WAKE_REASON_PACKET_INIT** function initializes a [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure.

## Parameters

### `Reason` [_Out_]

A pointer to a driver allocated [**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet) structure.

## Remarks

This function zeroes out the memory for the **NET_ADAPTER_WAKE_REASON_PACKET** structure, then sets the **Size** member.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_REASON_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_reason_packet)