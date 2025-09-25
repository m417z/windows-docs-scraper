# NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES structure

## Description

The **NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES** structure describes a net adapter's wake on LAN (WoL) capabilities for waking from a packet filter match.

## Members

### `Size`

The size of this structure, in bytes.

### `PacketFilterMatch`

A boolean value that describes if the net adapter is capable of waking from a packet filter match.

## Remarks

Call [**NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_packet_filter_capabilities_init) to initialize this structure, then call [**NetAdapterWakeSetPacketFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetpacketfiltercapabilities) to set the net adapter's packet filter WoL capabilities. Client drivers typically call **NetAdapterWakeSetPacketFilterCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_packet_filter_capabilities_init)

[**NetAdapterWakeSetPacketFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetpacketfiltercapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)