# StorPortReady function

## Description

The **StorPortReady** routine notifies the port driver that the adapter is no longer busy.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

## Return value

**StorPortReady** returns **TRUE** if the miniport driver succeeded in notifying the port driver and **FALSE** if not.

## Remarks

The functionality provided by this routine is exclusive to the Storport driver library. It has no parallel in the library of ScsiPort support routines.

## See also

[StorPortBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbusy)