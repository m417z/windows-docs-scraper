# NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED function

## Description

The **NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED** function initializes a [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure for a net adapter that would like to specify driver-managed receive buffer allocation and attachment.

## Parameters

### `RxCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure.

### `EvtAdapterReturnRxBuffer` [_In_]

A pointer to the client driver's *EVT_NET_ADAPTER_RETURN_RX_BUFFER* callback function. For more information, see the Remarks section.

### `MaximumFrameSize` [_In_]

The maximum frame size, in bytes, that the adapter can receive.

### `MaximumNumberOfQueues` [_In_]

The maximum number of receive queues that the adapter supports.

## Remarks

This function is one of three possible functions to call in order to initialize a [**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure. Which one the client driver should call depends on how it would like to allocate receive buffers and if it would like to use DMA.

The client driver must call **NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED** to initialize its **NET_ADAPTER_RX_CAPABILITIES** structure if it would like to perform manual receive buffer allocation and attachment. By calling this function, the Rx capabilities structure's **AllocationMode** member is set to **NetRxFragmentBufferAllocationModeDriver** and the **AttachmentMode** member is set to **NetRxFragmentBufferAttachmentModeDriver**. In this case, it must also provide a pointer to its *EVT_NET_ADAPTER_RETURN_RX_BUFFER* callback function in the structure for the operating system to invoke once the system has finished with the receive buffer.

## See also

[**NET_ADAPTER_RX_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)

[**NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed)

[**NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed_dma)