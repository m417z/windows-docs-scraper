# AtaPortCompleteAllActiveRequests function

## Description

The **AtaPortCompleteAllActiveRequests** routine completes all active IRBs for the indicated device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Target` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number of the device.

### `IrbStatus` [in]

Specifies the status with which the requests will be completed.

## Remarks

The **AtaPortCompleteAllActiveRequests** routine completes all active IRBs on the device as indicated by the *Target* and *Lun* parameters. Miniport drivers use this routine to complete all active IRPs if there is a reset. Miniport drivers can complete IRBs on all devices concurrently by assigning a value of IDE_UNTAGGED to the *Target* and *Lun* parameters, instead of specifying a specific device.

The miniport driver must not call this routine from the [IdeHwInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt) routine.

## See also

[IdeHwInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt)