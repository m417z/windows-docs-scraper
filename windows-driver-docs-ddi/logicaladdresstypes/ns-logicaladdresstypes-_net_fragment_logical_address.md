# NET_FRAGMENT_LOGICAL_ADDRESS structure

## Description

The **NET_FRAGMENT_LOGICAL_ADDRESS** structure contains DMA logical address information for a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment).

## Members

### `LogicalAddress`

On DMA capable adapters, contains a mapped DMA address that can be used to program NIC hardware.

Do not modify this value.

## Remarks

NetAdapterCx automatically registers the **NET_FRAGMENT_LOGICAL_ADDRESS** extension when the driver advertises DMA capabilities for the receive or transmit path.

To advertise DMA for the receive path, the driver must set the **DmaCapabilities** member in [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) and call [NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed_dma) to initialize the structure.

To advertise DMA for the transmit path, the driver must set the **DmaCapabilities** member in [**NET_ADAPTER_TX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) and call [NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init_for_dma) to initialize the structure.

To obtain this structure, call [**NetExtensionGetFragmentLogicalAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/logicaladdress/nf-logicaladdress-netextensiongetfragmentlogicaladdress).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NetExtensionGetFragmentLogicalAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/logicaladdress/nf-logicaladdress-netextensiongetfragmentlogicaladdress)

[**NET_ADAPTER_TX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities)

[**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)