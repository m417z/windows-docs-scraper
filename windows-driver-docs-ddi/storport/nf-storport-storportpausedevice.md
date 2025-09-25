# StorPortPauseDevice function

## Description

The **StorPortPauseDevice** routine pauses a specific logical unit device for the specified period of time.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit number of the target device.

### `Timeout`

Contains the interval of time that the device is to be paused, in seconds.

## Return value

**StorPortPauseDevice** returns **TRUE** if the miniport driver succeeded in pausing the device, **FALSE** if not.

## Remarks

When the time-out expires, I/O requests to the device will be resumed.

## See also

[StorPortResumeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportresumedevice)