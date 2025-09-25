# StorPortResumeDevice function

## Description

The **StorPortResumeDevice** routine resumes a previously paused logical unit.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit number of the target device.

## Return value

**StorPortResumeDevice** returns **TRUE** if the miniport driver succeeded in resuming the paused device, **FALSE** if not.

## See also

[StorPortPauseDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpausedevice)