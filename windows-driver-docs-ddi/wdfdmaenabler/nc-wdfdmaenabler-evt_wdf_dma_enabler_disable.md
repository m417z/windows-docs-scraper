# EVT_WDF_DMA_ENABLER_DISABLE callback function

## Description

[Applies to KMDF only]

A driver's *EvtDmaEnablerDisable* event callback function disables a device's DMA capability before the device leaves its working (D0) state.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object.

## Return value

*EvtDmaEnablerDisable* must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**, if it encounters no errors. Otherwise, this callback function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

To register an *EvtDmaEnablerDisable* callback function, a function driver for a DMA device places the callback function's address in a [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure before the driver calls [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

For more information about the *EvtDmaEnablerDisable* callback function, see [Supporting Power Management for DMA Devices](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-power-management-for-dma-devices).

## See also

[EvtDmaEnablerEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_enable)

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)