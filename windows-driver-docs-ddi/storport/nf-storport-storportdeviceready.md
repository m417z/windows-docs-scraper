# StorPortDeviceReady function

## Description

The **StorPortDeviceReady** routine notifies the port driver that the indicated logical unit is ready to handle new requests.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the given buses.

### `Lun` [in]

Identifies the logical unit for the given target controller or device.

## Return value

**StorPortDeviceReady** returns **TRUE** if the miniport driver succeeded in notifying the port driver, **FALSE** if not.

## Remarks

It is not generally necessary to notify the target device that new requests are required.

## See also

[StorPortDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportdevicebusy)

[StorPortReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportready)