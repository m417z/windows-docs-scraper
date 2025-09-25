# StorPortBusy function

## Description

The **StorPortBusy** routine notifies the port driver that the adapter is currently busy, handling outstanding requests.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `RequestsToComplete` [in]

Indicates the number of requests that the adapter must complete before resuming I/O requests to the miniport driver. If *RequestsToComplete* is greater than the number of currently outstanding requests, the Storport driver will complete all outstanding requests to the adapter before resuming requests.

## Return value

**StorPortBusy** returns **TRUE** if the miniport driver succeeded in notifying the port driver, **FALSE** if not.

## Remarks

The Storport driver will hold any number of requests until the adapter has completed enough outstanding requests so that it may continue processing requests.

The library of support routines provided by the SCSI Port driver does not include any routine similar to this one. This functionality is only available with the Storport driver library.

## See also

[StorPortReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportready)