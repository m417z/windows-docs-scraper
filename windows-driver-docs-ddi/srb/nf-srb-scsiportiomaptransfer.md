# ScsiPortIoMapTransfer function

## Description

The **ScsiPortIoMapTransfer** routine sets up the system DMA controller for a miniport driver to transfer data through a subordinate HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in]

Pointer to the SCSI request block for the DMA transfer.

### `LogicalAddress` [in]

Specifies the starting address for the transfer operation. This value can be the base address of a buffer into which or from which data is to be transferred. This value can be an offset within such a buffer.

### `Length` [in]

Specifies the number of bytes to be transferred.

## Return value

None

## Remarks

Only miniport drivers of HBAs that use a system DMA controller (subordinate DMA) call **ScsiPortIoMapTransfer**. This routine must be called before such a miniport driver sets up its HBA to transfer data. The range specified by the *LogicalAddress* and *Length* must be within the buffer described by the given SRB.

After the operating system-specific port driver programs the system DMA controller, it calls the miniport driver's [HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85)) routine. *HwScsiDmaStarted* should program the HBA to begin the data transfer. Note that an HBA can interrupt between the miniport driver's call to **ScsiPortIoMapTransfer** and the operating system-specific port driver's call to the miniport driver's *HwScsiDmaStarted* routine.

## See also

[HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85))

[ScsiPortFlushDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportflushdma)