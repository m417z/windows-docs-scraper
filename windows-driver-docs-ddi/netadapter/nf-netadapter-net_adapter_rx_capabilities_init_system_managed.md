# NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED function

## Description

The **NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED** function initializes a [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure for a net adapter that would like to specify operating system-managed receive buffer allocation and attachment, but not the use of DMA memory mapping.

## Parameters

### `RxCapabilities` [_Out_]

A pointer to a driver-allocated [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure.

### `MaximumFrameSize` [_In_]

The maximum frame size, in bytes, that the adapter can receive.

### `MaximumNumberOfQueues` [_In_]

The maximum number of receive queues that the adapter supports.

## Remarks

This function is one of three possible functions to call in order to initialize a [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure. Which one the client driver should call depends on how it would like to allocate receive buffers and if it would like to use DMA.

The client driver must call **NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED** to initialize its **NET_ADAPTER_RX_CAPABILITIES** structure if it would like the operating system to perform receive buffer allocation and attachment, but does not require DMA memory mapping. By calling this function, the Rx capabilities structure's **AllocationMode** member is set to **NetRxFragmentBufferAllocationModeSystem** and the **AttachmentMode** member is set to **NetRxFragmentBufferAttachmentModeSystem**. Because the driver does not specify DMA capabilities in this case, this function also sets the **MappingRequirement** member to **NetMemoryMappingRequirementNone**.

## See also

[NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)

[NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_driver_managed)

[NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed_dma)