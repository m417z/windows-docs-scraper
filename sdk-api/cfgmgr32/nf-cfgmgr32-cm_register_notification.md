# CM_Register_Notification function

## Description

The **CM_Register_Notification** function registers an application callback routine to be called when a PnP event of the specified type occurs.

Use [RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa) instead of **CM_Register_Notification** if your code targets Windows 7 or earlier versions of Windows. Kernel mode callers should use [IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-ioregisterplugplaynotification) instead.

## Parameters

### `pFilter` [in]

Pointer to a [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure.

### `pContext` [in, optional]

Pointer to a caller-allocated buffer containing the context to be passed to the callback routine in *pCallback*.

### `pCallback` [in]

Pointer to the routine to be called when the specified PnP event occurs. See the **Remarks** section for the callback function's prototype.

The callback routine’s *Action* parameter will be a value from the [CM_NOTIFY_ACTION](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ne-cfgmgr32-cm_notify_action) enumeration.

Upon receiving a notification, how the callback examines the notification will depend on the **FilterType** member of the callback routine's *EventData* parameter:

#### CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE

The callback should examine **EventData->u.DeviceInterface**.

#### CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE

The callback should examine **EventData->u.DeviceHandle**.

#### CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE

The callback should examine **EventData->u.DeviceInstance**.

### `pNotifyContext` [out]

Pointer to receive the HCMNOTIFICATION handle that corresponds to the registration call.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Be sure to handle Plug and Play device events as quickly as possible. If your event handler performs any operation that may block execution (such as I/O), it is best to start another thread to perform the operation asynchronously.

The **CM_Register_Notification** function does not provide notification of existing device interfaces. To retrieve existing interfaces, first call **CM_Register_Notification**, and then call [CM_Get_Device_Interface_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_lista). If the interface is enabled after your driver calls **CM_Register_Notification**, but before your driver calls **CM_Get_Device_Interface_List**, the driver receives a notification for the interface arrival, and the interface also appears in the list of device interface instances returned by **CM_Get_Device_Interface_List**.

HCMNOTIFICATION handles returned by **CM_Register_Notification** must be closed by calling the [CM_Unregister_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_unregister_notification) function when they are no longer needed.

A callback routine uses the following function prototype:

```cpp
typedef __callback DWORD (CALLBACK *PCM_NOTIFY_CALLBACK)(
    _In_ HCMNOTIFICATION       hNotify,
    _In_opt_ PVOID             Context,
    _In_ CM_NOTIFY_ACTION      Action,
    _In_reads_bytes_(EventDataSize) PCM_NOTIFY_EVENT_DATA EventData,
    _In_ DWORD                 EventDataSize
    );
```

If responding to a **CM_NOTIFY_ACTION_DEVICEQUERYREMOVE** notification, the PCM_NOTIFY_CALLBACK callback should return either ERROR_SUCCESS or ERROR_CANCELLED, as appropriate. Otherwise, the callback should return ERROR_SUCCESS. The callback should not return any other values. For a description of other actions, please refer to the [CM_NOTIFY_ACTION](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ne-cfgmgr32-cm_notify_action) documentation. Also see [CM_NOTIFY_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_event_data) for information about the structure that this callback receives in the *EventData* parameter.

#### Examples

For an example, see [Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal).

## See also

[CM_NOTIFY_ACTION](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ne-cfgmgr32-cm_notify_action)

[CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter)

[CM_Unregister_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_unregister_notification)

[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa)

[Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal)

[Using Device Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces)