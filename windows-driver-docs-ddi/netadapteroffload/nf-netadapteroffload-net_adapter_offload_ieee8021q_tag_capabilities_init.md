## Description

The **NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities) structure.

## Parameters

### `Ieee8021qCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities) structure.

### `Flags` [_In_]

Flags specifying whether the NIC can perform IEEE 802.1 priority and VLAN tagging.

## Remarks

The client driver calls **NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities) structure. The driver passes the initialized **NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES** structure as a parameter to the [**NetAdapterOffloadSetIeee8021qTagCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetieee8021qtagcapabilities) function to register it.

## See also

[**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities)

[**NetAdapterOffloadSetIeee8021qTagCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetieee8021qtagcapabilities)