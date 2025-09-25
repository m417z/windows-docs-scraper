# NetDmaProviderStop function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaProviderStop** function notifies the NetDMA interface that all of the DMA channels that are
associated with a DMA provider are no longer available for DMA transfers.

## Parameters

### `NetDmaProviderHandle` [in]

A handle that identifies a DMA provider. The DMA provider driver received this handle from the
NetDMA interface in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

## Return value

None

## Remarks

A DMA provider driver calls the
**NetDmaProviderStop** function to notify the NetDMA interface that a DMA engine, which was started by
calling the
[NetDmaProviderStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstart) function, is no
longer available.

The DMA provider driver must call
**NetDmaProviderStop** before it calls the
[NetDmaDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaderegisterprovider) function
to deregister a DMA provider.

DMA provider drivers typically call
**NetDmaProviderStop** while handling the
[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) or
[IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device) IRP.

A DMA provider driver can call
**NetDmaProviderStop** and
[NetDmaProviderStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstart) as many times as
the application requires after registering the DMA provider and before deregistering the DMA provider. If
a DMA engine is being restarted after it called
**NetDmaProviderStop**, the DMA provider driver can specify new attributes in the
[NET_DMA_PROVIDER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_attributes) structure at the
*ProviderAttributes* parameter of
**NetDmaProviderStart**.

The NetDMA interface waits for outstanding DMA operations to complete and frees all of the allocated
DMA channels before it returns from the
**NetDmaProviderStop** function.

## See also

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device)

[NET_DMA_PROVIDER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_attributes)

[NetDmaDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaderegisterprovider)

[NetDmaProviderStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstart)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)