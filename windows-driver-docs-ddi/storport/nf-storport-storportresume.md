# StorPortResume function

## Description

The **StorPortResume** routine resumes a paused adapter.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

## Return value

**StorPortResume** returns **TRUE** if the miniport driver succeeded in resuming the paused adapter, **FALSE** if not.

## See also

[StorPortPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpause)