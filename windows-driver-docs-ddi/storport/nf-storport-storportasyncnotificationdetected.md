# StorPortAsyncNotificationDetected function

## Description

A storage miniport driver calls **StorPortAsyncNotificationDetected** to notify the Storport driver of a storage device status change event.

The notification is queued as a work item for deferred processing at DISPATCH_LEVEL or lower IRQL.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Address`

The address of the storage device with a status change event.

### `Flags`

The status notifications to indicate to Storport.

The Flags parameter contains a bitwise OR combination of status notifications. All status values can be set with the single **RAID_ASYNC_NOTIFY_SUPPORTED_FLAGS** value.

| Value | Meaning |
| --- | --- |
| **RAID_ASYNC_NOTIFY_FLAG_MEDIA_STATUS** | Notify Storport that a media change occurred. |
| **RAID_ASYNC_NOTIFY_FLAG_DEVICE_STATUS** | Notify Storport that the functional status of the storage device has changed. |
| **RAID_ASYNC_NOTIFY_FLAG_DEVICE_OPERATION** | Notify Storport that an operational role of the storage device has changed. |

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The state change notification is scheduled for processing. |
| **STOR_STATUS_INVALID_PARAMETER** | The address type invalid.<br><br>-or-<br><br>*HwDeviceExtension* is **NULL**.<br><br>-or-<br><br>*Flags* contains an undefined value. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The storage device unit cannot be found at *address*.<br><br>-or-<br><br>The storage device does not support asynchronous notifications. |
| **STOR_STATUS_BUSY** | A prior notification is in process and this one cannot be scheduled. |

## Remarks

A miniport can detect status events in its [HwStorInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) routine and call **StorPortAsyncNotificationDetected** to queue and process the status change notification later at a lower IRQL.

When processed by Storport, the status event notification is forwarded to the storage class driver to initiate any necessary system response actions.

If the *Flags* parameter is 0, Storport will indicate all status values in its notification to the storage class driver.