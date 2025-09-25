## Description

The **NetAdapterOffloadSetIeee8021qTagCapabilities** function sets the IEEE 802.1 priority tagging and virtual LAN (VLAN) tagging capabilities of a network adapter.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `HardwareCapabilities` [In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities) structure that describes the hardware's 802.1 priority tagging and VLAN tagging capabilities.

## Remarks

Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities)

[**NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities_init)