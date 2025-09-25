# ScsiPortFlushDma function

## Description

The **ScsiPortFlushDma** routine flushes any data cached in the system DMA controller at the end of a transfer or terminates a system DMA transfer.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

## Return value

None

## Remarks

Only miniport drivers of subordinate HBAs that use a system DMA controller call this routine.

**ScsiPortFlushDma** must be called after a subordinate DMA transfer operation is completed but before the SRB is completed or the next call is made to [ScsiPortIoMapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportiomaptransfer) for the current buffer.

**ScsiPortFlushDma** also must be called after **ScsiPortIoMapTransfer** to cancel a DMA operation, even if no transfer has occurred and the driver's [HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85)) routine has not yet been called.

## See also

[HwScsiDmaStarted](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557291(v=vs.85))

[ScsiPortIoMapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportiomaptransfer)