# NetDmaDeregisterProvider function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaDeregisterProvider** function deregisters a DMA provider.

## Parameters

### `NetDmaProviderHandle` [in]

A handle that identifies a DMA provider. The DMA provider driver received this handle from the
NetDMA interface in a call to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

## Return value

None

## Remarks

DMA provider drivers call the
**NetDmaDeregisterProvider** function to deregister a DMA provider that was previously registered by
calling the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

The DMA provider driver must call the
[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop) function before it
deregisters a DMA provider. The DMA provider driver calls
**NetDmaProviderStop** to notify the NetDMA interface that a previously started DMA provider is no
longer available.

A DMA provider driver typically calls the
**NetDmaDeregisterProvider** function in the context of processing the
[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) IRP for the DMA
provider.

Call
**NetDmaDeregisterProvider** at IRQL = PASSIVE_LEVEL.

## See also

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)