# NetAdapterWakeSetMagicPacketCapabilities function

## Description

The **NetAdapterWakeSetMagicPacketCapabilities** function sets a net adapter's magic packet wake on LAN (WoL) capabilities.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities` [_In_]

A pointer to a client driver-allocated and initialized [**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_magic_packet_capabilities) structure.

## Remarks

Client drivers must call [**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_magic_packet_capabilities_init) to initialize the **NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES** structure, then set the structure's members appropriately before calling this function. Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_wake_magic_packet_capabilities)

[**NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_wake_magic_packet_capabilities_init)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)