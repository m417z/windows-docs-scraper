# AtaPortDeviceReady function

## Description

The **AtaPortDeviceReady** routine informs the port driver that the indicated device is ready to accept new requests.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `TargetId` [in]

Specifies the target identifier of the device.

### `Lun` [in]

Specifies the logical unit number (LUN) of the device.

## Remarks

The port driver resumes the paused request queue for the indicated device. If the caller assigns a wildcard value of IDE_UNTAGGED to parameters *TargetId* and *Lun*, the port driver will restart the channel request queue.

## See also

[AtaPortDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportdevicebusy)