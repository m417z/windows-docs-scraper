# NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA function

## Description

The **NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA** function initializes a [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure for a net adapter that would like to specify operating system-managed receive buffer allocation and attachment, as well as DMA for memory mapping.

## Parameters

### `RxCapabilities` [_Out_]

A pointer to a driver-allocated [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure.

### `DmaCapabilities` [_In_]

A pointer to a driver-allocated and initialized [NET_ADAPTER_DMA_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure.

### `MaximumFrameSize` [_In_]

The maximum frame size, in bytes, that the adapter can receive.

### `MaximumNumberOfQueues` [_In_]

The maximum number of receive queues that the adapter supports.

## Remarks

This function is one of three possible functions to call in order to initialize a [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure. Which one the client driver should call depends on how it would like to allocate receive buffers and if it would like to use DMA.

The client driver must call **NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA** to initialize its **NET_ADAPTER_RX_CAPABILITIES** structure if it would like the operating system to perform receive buffer allocation and attachment, and if it would also like to use DMA in its receive data path. By calling this function, the Rx capabilities structure's **AllocationMode** member is set to **NetRxFragmentBufferAllocationModeSystem** and the **AttachmentMode** member is set to **NetRxFragmentBufferAttachmentModeSystem**.

Before calling **NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA**, the driver must have allocated a [NET_ADAPTER_DMA_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure and initialized it with [NET_ADAPTER_DMA_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_dma_capabilities_init). This DMA capabilities structure is then assigned to the **DmaCapabilities** member of the **NET_ADAPTER_RX_CAPABILITIES** structure.

## See also

[NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)

[NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_driver_managed)

[NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed)