# _WDF_DMA_SYSTEM_PROFILE_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_DMA_SYSTEM_PROFILE_CONFIG** structure describes the hardware-specific settings related to a system-mode DMA enabler.

## Members

### `Size`

The size of this structure in bytes.

### `DemandMode`

Specifies that the transfer is controlled by the device's DMA
request line specified in the **DmaDescriptor** member of this structure. See more information in Remarks.

### `LoopedTransfer`

Specifies that the DMA adapter should loop around the specified transfer if the length is greater than the size of the buffer.

### `DmaWidth`

The width of the register specified by **DeviceAddress**. Possible values are Width8Bits, Width16Bits, Width32Bits, and Width64Bits.

### `DeviceAddress`

The translated address to or from which the DMA controller transfers. The driver can specify an offset from this base address on each transaction by calling [WdfDmaTransactionSetDeviceAddressOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetdeviceaddressoffset).

### `DmaDescriptor`

The translated resource descriptor for the DMA channel assigned
the device during [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware). This provides the DMA request line for the adapter.

## Remarks

The driver provides this structure to [WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile) after creating a system-profile DMA enabler.

Typically, drivers set **DemandMode** to TRUE. The driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) callback function then programs the device to assert its DMA request line and initiate the transfer. In this case, the transfer might begin while *EvtProgramDma* is still running.

The driver must ensure that the device's DMA request line is not asserted before the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) callback function begins execution. Otherwise, it is possible for the DMA transfer to begin before the framework calls *EvtProgramDma*.

If **DemandMode** is set to FALSE, the DMA transfer may begin before the framework calls the driver’s [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) function.

## See also

[WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_system_profile_config_init)

[WdfDmaEnablerConfigureSystemProfile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablerconfiguresystemprofile)