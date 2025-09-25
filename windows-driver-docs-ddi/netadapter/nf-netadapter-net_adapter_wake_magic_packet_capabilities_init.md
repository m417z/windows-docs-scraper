# NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_magic_packet_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a client driver-allocated [*NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_magic_packet_capabilities) structure.

## Remarks

This function zeroes out the memory for the **NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES** structure, then sets the **Size** member. After calling this function to initialize the **NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES** structure, set the remaining members of the structure according to your hardware's capabilities, then call [**NetAdapterWakeSetMagicPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmagicpacketcapabilities) to set the net adapter's magic packet wake on LAN (WoL) capabilities. Client drivers typically call **NetAdapterWakeSetMagicPacketCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_magic_packet_capabilities)

[**NetAdapterWakeSetMagicPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmagicpacketcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)