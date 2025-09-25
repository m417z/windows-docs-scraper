## Description

The **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities) structure.

## Remarks

The client driver calls **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities) structure. The driver passes the initialized **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES** structure as a parameter to the [**NetAdapterWakeSetEapolPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakeseteapolpacketcapabilities) function to register it.

## See also

[**NetAdapterWakeSetEapolPacketCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterwakeseteapolpacketcapabilities)

[**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities)