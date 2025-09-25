# _NET_ADAPTER_DMA_CAPABILITIES structure

## Description

The **NET_ADAPTER_DMA_CAPABILITIES** structure describes the DMA capabilities of a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `DmaEnabler`

The DMA enabler object used by the client driver to map and allocate memory.

> [!IMPORTANT]
> When configuring this object with the [**WDF_DMA_ENABLER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure, client drivers must set the **WdmDmaVersionOverride** member to **3** to specify DMA version 3.

### `MaximumPhysicalAddress`

The maximum physical address to use when allocating memory buffers. Set this member to **0** to indicate that there is no maximum address.

### `CacheEnabled`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state) value that defines if the memory allocated should have cache enabled or not. If this member is set to **WdfDefault**, cache will be enabled only if the device is cache coherent.

### `PreferredNode`

The preferred NUMA node to use when allocating memory. If this member is set to **MM_ANY_NODE_OK**, NetAdapterCx will automatically determine the best node to use.

## Remarks

Call [NET_ADAPTER_DMA_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_dma_capabilities_init) to initialize this structure.

This structure can be used either in the receive path, as a member of the [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure, or in the transmit path as a member of the [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init_for_dma) structure.

## See also

[NET_ADAPTER_DMA_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_dma_capabilities_init)

[NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)

[NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init_for_dma)