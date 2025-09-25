# StorPortDeviceBusy function

## Description

The **StorPortDeviceBusy** routine notifies the port driver that the specified logical unit is currently busy, handling outstanding requests.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the given buses.

### `Lun` [in]

Identifies the logical unit for the given target controller or device.

### `RequestsToComplete` [in]

Indicates the number of requests that the logical unit must complete before resuming I/O requests to the miniport driver. If *RequestsToComplete* is greater than the number of currently outstanding requests, the Storport driver will complete all outstanding requests to the logical unit before resuming requests.

## Return value

**StorPortDeviceBusy** returns **TRUE** if the miniport driver succeeded in notifying the port driver, **FALSE** if not.

## Remarks

No error log is generated when a device is busy.

The port driver will not issue any new requests to the logical unit until the logical unit's queue has been drained to a sufficient level where processing can continue.

## See also

[StorPortBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbusy)

[StorPortReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportready)