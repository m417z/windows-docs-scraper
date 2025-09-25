# AtaPortDeviceBusy function

## Description

The **AtaPortDeviceBusy** routine informs the port driver that the indicated device is busy.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `TargetId` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number (LUN) of the device.

### `BusyTimeout` [in]

Specifies the time, in seconds, for which the device is presumed to be busy.

## Remarks

When the port driver receives this call, it pauses the request queue for the indicated device for the time that is indicated by *BusyTimeout*. The caller can pause the channel request queue instead of the request queue for an individual device by assigning the wildcard value of IDE_UNTAGGED to parameters *TargetId* and *Lun*.

The port driver automatically resumes paused queues after the time-out interval expires.

The miniport driver must not call **AtaPortDeviceBusy** from its [IdeHwInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt) routine.

## See also

[AtaPortDeviceReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportdeviceready)

[IdeHwInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt)