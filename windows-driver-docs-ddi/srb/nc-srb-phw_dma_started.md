# PHW_DMA_STARTED callback

## Description

The PHW_DMA_STARTED routine prototype declares a SCSI miniport driver routine that starts DMA for subordinate DMA device.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

## Remarks

If the HBA is a subordinate DMA device, the SCSI miniport driver's [HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85)) routine is called after the OS-specific port driver has set up the system DMA controller for a DMA transfer.

Miniport drivers that work with the StorPort driver do not support adapters that require subordinate DMA.

## See also

[HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85))