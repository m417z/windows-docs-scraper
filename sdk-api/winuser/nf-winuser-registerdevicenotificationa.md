# RegisterDeviceNotificationA function

## Description

Registers the device or type of device for which a window will receive notifications.

> [!NOTE]
> You can use [CM_Register_Notification](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) instead of **RegisterDeviceNotification** if your code targets Windows 8 or newer versions of Windows. The advantage of **CM_Register_Notification** is that it does not require a window handle to work.

## Parameters

### `hRecipient` [in]

A handle to the window or service that will receive device events for the devices specified in the
*NotificationFilter* parameter. The same window handle can be used in multiple calls to
**RegisterDeviceNotification**.

Services can specify either a window handle or service status handle.

### `NotificationFilter` [in]

A pointer to a block of data that specifies the type of device for which notifications should be sent. This
block always begins with the [DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)
structure. The data following this header is dependent on the value of the
**dbch_devicetype** member, which can be
**DBT_DEVTYP_DEVICEINTERFACE** or **DBT_DEVTYP_HANDLE**. For more
information, see Remarks.

### `Flags` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DEVICE_NOTIFY_WINDOW_HANDLE**<br><br>0x00000000 | The *hRecipient* parameter is a window handle. |
| **DEVICE_NOTIFY_SERVICE_HANDLE**<br><br>0x00000001 | The *hRecipient* parameter is a service status handle. |

In addition, you can specify the following value.

| Value | Meaning |
| --- | --- |
| **DEVICE_NOTIFY_ALL_INTERFACE_CLASSES**<br><br>0x00000004 | Notifies the recipient of device interface events for all device interface classes. (The **dbcc_classguid** member is ignored.)<br><br>This value can be used only if the **dbch_devicetype** member is **DBT_DEVTYP_DEVICEINTERFACE**. |

## Return value

If the function succeeds, the return value is a device notification handle.

If the function fails, the return value is **NULL**. To get extended error information,
call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications send event notifications using the
[BroadcastSystemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessage) function. Any
application with a top-level window can receive basic notifications by processing the
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange) message. Applications can use the
**RegisterDeviceNotification** function to
register to receive device notifications.

Services can use the
**RegisterDeviceNotification** function to
register to receive device notifications. If a service specifies a window handle in the
*hRecipient* parameter, the notifications are sent to the window procedure. If
*hRecipient* is a service status handle,
**SERVICE_CONTROL_DEVICEEVENT** notifications are sent to the service control handler. For
more information about the service control handler, see
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex).

Be sure to handle Plug and Play device events as quickly as possible. Otherwise, the system may become
unresponsive. If your event handler is to perform an operation that may block execution (such as I/O), it is best
to start another thread to perform the operation asynchronously.

Device notification handles returned by
**RegisterDeviceNotification** must be closed
by calling the
[UnregisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterdevicenotification) function
when they are no longer needed.

The [DBT_DEVICEARRIVAL](https://learn.microsoft.com/windows/desktop/DevIO/dbt-devicearrival) and
[DBT_DEVICEREMOVECOMPLETE](https://learn.microsoft.com/windows/desktop/DevIO/dbt-deviceremovecomplete) events are
automatically broadcast to all top-level windows for port devices. Therefore, it is not necessary to call
**RegisterDeviceNotification** for ports, and
the function fails if the **dbch_devicetype** member is
**DBT_DEVTYP_PORT**. Volume notifications are also broadcast to top-level windows, so the
function fails if **dbch_devicetype** is **DBT_DEVTYP_VOLUME**.
OEM-defined devices are not used directly by the system, so the function fails if
**dbch_devicetype** is **DBT_DEVTYP_OEM**.

#### Examples

For an example, see
[Registering for device notification](https://learn.microsoft.com/windows/desktop/DevIO/registering-for-device-notification).

> [!NOTE]
> The winuser.h header defines RegisterDeviceNotification as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BroadcastSystemMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-broadcastsystemmessage)

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[Device Management Functions](https://learn.microsoft.com/windows/desktop/DevIO/device-management-functions)

[Device Notifications](https://learn.microsoft.com/windows/desktop/DevIO/device-notifications)

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa)

[UnregisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterdevicenotification)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)