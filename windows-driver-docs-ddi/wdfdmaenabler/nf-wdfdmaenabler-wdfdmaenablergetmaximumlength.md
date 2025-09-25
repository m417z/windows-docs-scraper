# WdfDmaEnablerGetMaximumLength function

## Description

[Applies to KMDF only]

The **WdfDmaEnablerGetMaximumLength** method returns the maximum transfer length, for a single [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers), that a device supports.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object that the driver obtained from a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

## Return value

**WdfDmaEnablerGetMaximumLength** returns the maximum length of a DMA transfer, in bytes. This length is the same value that was specified in a previous call to [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaEnablerGetFragmentLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablergetfragmentlength)