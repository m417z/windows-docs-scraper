# EVT_WDF_DMA_ENABLER_FILL callback function

## Description

[Applies to KMDF only]

A driver's *EvtDmaEnablerFill* event callback function allocates a device's DMA buffers.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object.

## Return value

*EvtDmaEnablerFill* must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**, if it encounters no errors. Otherwise, this callback function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

To register an *EvtDmaEnablerFill* callback function, a function driver for a DMA device places the callback function's address in a [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure before the driver calls [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

For more information about the *EvtDmaEnablerFill* callback function, see [Supporting Power Management for DMA Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-power-management-for-dma-devices).

The *EvtDmaEnablerFill* callback function is called at IRQL = PASSIVE_LEVEL. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[EvtDmaEnablerFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_flush)

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)