## Description

The **NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES** structure describes a network interface card (NIC)'s IEEE 802.1 priority tagging and virtual LAN (VLAN) tagging capabilities.

## Members

### `Size`

The size of this structure in bytes.

### `Flags`

Flags specifying whether the NIC can perform IEEE 802.1 priority and VLAN tagging.

| Flag | Description |
| --- | --- |
| NetAdapterOffloadIeee8021PriorityTaggingFlag | Set if the NIC is capable of performing IEEE 802.1 priority tagging. |
| NetAdapterOffloadIeee8021VlanTaggingFlag | Set if the NIC is capable of performing VLAN tagging. |

## Remarks

Call [**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities_init) to initialize this structure. The client driver passes an initialized **NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES** structure as a parameter to [**NetAdapterOffloadSetIeee8021qTagCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetieee8021qtagcapabilities).

## See also

[**NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities_init)

[**NetAdapterOffloadSetIeee8021qTagCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetieee8021qtagcapabilities)