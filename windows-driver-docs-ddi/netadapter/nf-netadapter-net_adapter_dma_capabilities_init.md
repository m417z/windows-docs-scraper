# NET_ADAPTER_DMA_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_DMA_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_DMA_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure.

## Parameters

### `DmaCapabilities` [_Out_]

A pointer to the driver-allocated **NET_ADAPTER_DMA_CAPABILITIES** structure to be initialized.

### `DmaEnabler` [_In_]

A DMA enabler object the client driver obtained in a previous call to [**WdfDmaEnablerCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

## Remarks

The client driver typically calls this function while setting capabilities for its data path, when it is starting a net adapter but before it calls [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also