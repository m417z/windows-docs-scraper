# WdfDevicePostEvent function

## Description

[Applies to UMDF only]

The **WdfDevicePostEvent** method asynchronously notifies applications that are waiting for the specified event from a driver.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `EventGuid` [in]

The GUID for the event. The GUID is determined by the application and the driver and is opaque to the framework.

### `WdfEventType` [in]

A [WDF_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_event_type)-typed value that identifies the type of event. In the current version of UMDF, the driver must set *EventType* to **WdfEventBroadcast** (1). **WdfEventBroadcast** indicates that the event is broadcast. Applications can subscribe to **WdfEventBroadcast**-type events. To receive broadcast events, the application must register for notification through the Microsoft Win32 **RegisterDeviceNotification** function. **WdfEventBroadcast**-type events are exposed as DBT_CUSTOMEVENT-type events to applications.

### `Data` [in]

A pointer to a buffer that contains data that is associated with the event. **NULL** is a valid value.

### `DataSizeCb` [in]

The size, in bytes, of data that *Data* points to. Zero is a valid size value if *Data* is set to **NULL**.

## Return value

If the operation succeeds, **WdfDevicePostEvent** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *WdfEventType* is not set to **WdfEventBroadcast**. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

When the driver calls **WdfDevicePostEvent** to notify the requesting application about an event, UMDF sends the event to the operating system. The operating system sends the event on to the requesting application in an asynchronous operation. If the operating system initially returns no error, **WdfDevicePostEvent** returns STATUS_SUCCESS.

 However, later, if the operating system receives an error while it attempts to deliver the event (possibly because of a low memory condition), the operating system is unable to inform the driver about the error. Because of the asynchronous nature of this event notification, delivery of the event to the requesting application is not guaranteed.

 If event information is lost on its way up to the requesting application, the application should be able to recover from the lost event.

## See also

[IWDFDevice::PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-postevent)

[WDF_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_event_type)