# WDF_DMA_ENABLER_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_DMA_ENABLER_CONFIG_INIT** function initializes a driver's [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

## Parameters

### `Config` [out]

A pointer to a driver-allocated [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

### `Profile` [in]

A value for the **Profile** member of the [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

### `MaximumLength` [in]

A value for the **MaximumLength** member of the [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

## Remarks

Drivers must call the **WDF_DMA_ENABLER_CONFIG_INIT** function before calling [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

#### Examples

For a code example that uses **WDF_DMA_ENABLER_CONFIG_INIT**, see [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)