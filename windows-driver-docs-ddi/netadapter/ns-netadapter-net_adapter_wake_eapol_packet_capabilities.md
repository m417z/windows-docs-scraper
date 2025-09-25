## Description

The **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES** structure describes a network adapter's wake on LAN (WoL) capabilities for waking from an EAP over LAN (EAPOL) request identifier message.

## Members

### `Size`

The size of this structure in bytes.

### `EapolPacket`

A boolean value that describes if the network adapter is capable of waking from an EAPOL packet.

## Remarks

Call [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_eapol_packet_capabilities_init) to initialize this structure, then call [**NetAdapterWakeSetEapolPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakeseteapolpacketcapabilities) to set the network adapter's EAPOL packet WoL capabilities. Client drivers typically call **NetAdapterWakeSetEapolPacketCapabilities** when starting a network adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

When reporting that a [**NET_WAKE_SOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ne-netwakesource-_net_wake_source_type) is
NetWakeSourceTypeEapolPacket, call [**NET_ADAPTER_WAKE_REASON_EAPOL_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_eapol_packet_init) to initialize a **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES** structure.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_eapol_packet_capabilities_init)

[**NET_ADAPTER_WAKE_REASON_EAPOL_PACKET_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_reason_eapol_packet_init)

[**NetAdapterWakeSetEapolPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakeseteapolpacketcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)