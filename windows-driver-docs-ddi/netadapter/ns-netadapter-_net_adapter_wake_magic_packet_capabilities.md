# NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES structure

## Description

The **NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES** structure describes a net adapter's wake on LAN (WoL) capabilities for waking from a magic packet.

## Members

### `Size`

The size of this structure, in bytes.

### `MagicPacket`

A boolean value that describes if the net adapter is capable of waking from a magic packet.

## Remarks

Call [**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_magic_packet_capabilities_init) to initialize this structure, then call [**NetAdapterWakeSetMagicPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmagicpacketcapabilities) to set the net adapter's magic packet WoL capabilities. Client drivers typically call **NetAdapterWakeSetMagicPacketCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_magic_packet_capabilities_init)

[**NetAdapterWakeSetMagicPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakesetmagicpacketcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)