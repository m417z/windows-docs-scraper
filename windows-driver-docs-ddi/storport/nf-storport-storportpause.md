# StorPortPause function

## Description

The **StorPortPause** routine pauses an adapter for the specified period of time.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension of the adapter to pause. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Timeout`

Specifies the interval of time, in seconds, that the adapter is to be paused.

## Return value

**StorPortPause** returns **TRUE** if the miniport driver succeeded in pausing the adapter, **FALSE** if not.

## Remarks

All requests to the adapter are held until the time-out expires or the device resumes. All requests to all targets attached to the adapter will be held until the adapter is resumed or the time-out expires.

## See also

[StorPortResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportresume)