# IWDFDevice::PostEvent

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **PostEvent** method asynchronously notifies applications that are waiting for the specified event from a driver.

## Parameters

### `EventGuid` [in]

The GUID for the event. The GUID is determined by the application and the driver and is opaque to the framework.

### `EventType` [in]

A [WDF_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_event_type)-typed value that identifies the type of event. In the current version of UMDF, the driver must set *EventType* to **WdfEventBroadcast** (1). **WdfEventBroadcast** indicates that the event is broadcast. Applications can subscribe to **WdfEventBroadcast**-type events. To receive broadcast events, the application must register for notification through the Microsoft Win32 **RegisterDeviceNotification** function. **WdfEventBroadcast**-type events are exposed as DBT_CUSTOMEVENT-type events to applications.

### `pbData` [in]

A pointer to a buffer that contains data that is associated with the event. **NULL** is a valid value.

### `cbDataSize` [in]

The size, in bytes, of data that *pbData* points to. Zero is a valid size value if *pbData* is set to **NULL**.

The maximum size of the event data is slightly less than MAXUSHORT (64 KB). The precise upper limit is (0xFFFF - [FIELD_OFFSET](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-field_offset)([TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification), CustomDataBuffer)).

## Return value

**PostEvent** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The event data was successfully sent to the operating system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_ENOUGH_MEMORY)** | The data size that the *cbDataSize* parameter specifies is larger than the maximum allowable size. |
| **E_INVALIDARG** | The *EventType* parameter is not set to **WdfEventBroadcast** (1). |
| **E_OUTOFMEMORY** | [PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-postevent) could not allocate memory that was required for it to complete. |

**PostEvent** might also return other HRESULT values.

## Remarks

When the driver calls **IWDFDevice::PostEvent** to notify the requesting application about an event, UMDF sends the event to the operating system. The operating system sends the event on to the requesting application in an asynchronous operation. If the operating system initially returns no error, the driver receives no error (S_OK). However, later, if the operating system receives an error while it attempts to deliver the event (possibly because of a low memory condition), the operating system is unable to inform the driver about the error. Because of the asynchronous nature of this event notification, delivery of the event to the requesting application is not guaranteed. If event information is lost on its way up to the requesting application, the application should be able to recover from the lost event.

For information about creating device events, see [Using Device Interfaces in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## See also

[FIELD_OFFSET](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-field_offset)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)

[WdfDevicePostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicepostevent)