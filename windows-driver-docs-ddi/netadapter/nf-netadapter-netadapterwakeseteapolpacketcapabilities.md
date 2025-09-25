## Description

The **NetAdapterWakeSetEapolPacketCapabilities** function sets a network adapter's EAP over LAN (EAPOL) packet wake on LAN (WoL) capabilities.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities` [_In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities) structure that describes the network adapter's EAPOL packet WoL capabilities.

## Remarks

Client drivers must call [**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_eapol_packet_capabilities_init) to initialize the **NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES** structure, then set the structure's members appropriately before calling this function. Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_wake_eapol_packet_capabilities)

[**NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_eapol_packet_capabilities_init)

[*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)