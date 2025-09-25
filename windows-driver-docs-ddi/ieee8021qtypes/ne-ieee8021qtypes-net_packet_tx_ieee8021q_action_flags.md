## Description

NetAdapterCx sets the **NET_PACKET_TX_IEEE8021Q_ACTION_FLAGS** enum to specify the IEEE 802.1 priority tagging and virtual LAN (VLAN) tagging capabilities that the client driver supports.

## Constants

### `NetPacketTxIeee8021qActionFlagPriorityRequired:1`

### `NetPacketTxIeee8021qActionFlagVlanRequired:2`

## Remarks

If only IEEE 802.1 priority tagging is supported, NetAdapterCx sets this value to 1.
If only VLAN tagging is supported, NetAdapterCx sets this value to 2.
If both are supported, NetAdapterCx sets this value to 3.

## See also

[**NET_ADAPTER_OFFLOAD_IEEE8021Q_TAG_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-net_adapter_offload_ieee8021q_tag_capabilities)