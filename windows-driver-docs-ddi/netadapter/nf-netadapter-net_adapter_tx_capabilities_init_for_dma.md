# NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA function

## Description

The **NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA** function initializes a [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) structure for a net adapter that has specified the use of DMA in its transmit data path.

## Parameters

### `TxCapabilities` [_Out_]

A pointer to a driver-allocated [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) structure.

### `DmaCapabilities` [_In_]

A pointer to a driver-allocated and initialized [NET_ADAPTER_DMA_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure.

### `MaximumNumberOfQueues` [_In_]

The maximum number of transmit queues that the adapter supports.

## Remarks

This function is one of two possible functions to call in order to initialize a [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) structure. Which one the client driver should call depends on whether it would like to use DMA. [NET_ADAPTER_TX_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init) is used if the driver does not specify DMA memory mapping for its transmit buffers, and **NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA** is used if it does.

Before calling **NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA**, the driver must have allocated a [NET_ADAPTER_DMA_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure and initialized it with [NET_ADAPTER_DMA_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_dma_capabilities_init). This DMA capabilities structure is then assigned to the **DmaCapabilities** member of the **NET_ADAPTER_TX_CAPABILITIES** structure.

## See also

[NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities)

[NET_ADAPTER_TX_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init)