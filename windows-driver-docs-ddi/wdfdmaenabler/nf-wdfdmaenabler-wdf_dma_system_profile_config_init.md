# WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT** function initializes a driver's [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config) structure.

## Parameters

### `DmaConfig`

A pointer to a driver-allocated [**WDF_DMA_SYSTEM_PROFILE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config) structure.

### `Address` [in]

The translated address of the register to target for DMA. For more information, see Remarks.

### `DmaWidth` [in]

The width of the register specified by **Address**.

### `DmaDescriptor` [in]

The translated resource descriptor for the DMA channel assigned
the device during [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

## Remarks

Typically, a driver calls **WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT** from within its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. A driver must call the **WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT** function before calling [WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile).

Depending on the System on a Chip (SoC) design, the *Address* parameter might have a different meaning. For example if DMA uses dedicated transfer ports on the device, *Address* might indicate the port to which DMA writes occur.

 For more information about creating a system-mode DMA enabler, see [Supporting System-Mode DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-mode-dma).

#### Examples

For a code example that uses **WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT**, see [WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile).

## See also

[WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config)

[WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)