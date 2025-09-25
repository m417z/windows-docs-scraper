# NotifyTeredoPortChange function

## Description

The
**NotifyTeredoPortChange** function registers to be notified for changes to the UDP port number used by the Teredo client for the Teredo service port on a local computer.

## Parameters

### `Callback` [in]

A pointer to the function to call when a Teredo client port change occurs. This function will be invoked
when a Teredo port change notification is received.

### `CallerContext` [in]

A user context passed to the callback function specified in the *Callback* parameter when a Teredo port change notification is received.

### `InitialNotification` [in]

A value that indicates whether the callback should be invoked
immediately after registration for change notification completes. This initial notification does not indicate a change occurred to the Teredo client port. The purpose of this parameter to provide confirmation that the callback is registered.

### `NotificationHandle` [in, out]

A pointer used to return a handle that can be later used to
deregister the change notification. On success, a notification handle is returned in this parameter. If an error occurs, **NULL** is returned.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Callback* parameter is a **NULL** pointer. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **NotifyTeredoPortChange** function is defined on Windows Vista and later.

The [GetTeredoPort](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getteredoport) function can be used to retrieve the initial UDP port number used by the Teredo client for the Teredo service port.

The Teredo port is dynamic and can change any time the Teredo client is restarted on the local computer. An application can register to be notified when the Teredo service port changes by calling the **NotifyTeredoPortChange** function.

The invocation of the callback function specified in the *Callback* parameter is serialized. The callback function should be defined as a function of type **VOID**. The parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID CallerContext | The *CallerContext* parameter passed to the **NotifyTeredoPortChange** function when registering for notifications. |
| IN USHORT Port | The UDP port number currently used by the Teredo client. This parameter is **zero** when the **MIB_NOTIFICATION_TYPE** value passed in the *NotificationType* parameter to the callback function is set to **MibInitialNotification**. This can only occur if the *InitialNotification* parameter passed to **NotifyTeredoPortChange** was set to **TRUE** when registering for notifications. |
| IN MIB_NOTIFICATION_TYPE NotificationType | The notification type. This member can be one of the values from the [MIB_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/netioapi/ne-netioapi-mib_notification_type) enumeration type defined in the *Netioapi.h* header file. |

The callback function specified in the *Callback* parameter must be implemented in the same process as the application calling the **NotifyTeredoPortChange** function. If the callback function is in a separate DLL, then the DLL should be loaded before calling the **NotifyTeredoPortChange** function to register for change notifications.

Once the **NotifyTeredoPortChange** function is called to register for change notifications, these notifications will continue to be sent until the application deregisters for change notifications or the application terminates. If the application terminates, the system will automatically deregister any registration for change notifications. It is still recommended that an application explicitly deregister for change notifications before it terminates.

Any registration for change notifications does not persist across a system shut down or reboot.

To deregister for change notifications, call the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function passing the *NotificationHandle* parameter returned by **NotifyTeredoPortChange**.

An application cannot make a call to the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function from the context of the thread which is currently executing the notification callback function for the same *NotificationHandle* parameter. Otherwise, the thread executing that callback will result in deadlock. So the **CancelMibChangeNotify2** function must not be called directly as part of the notification callback routine. In a more general situation, a thread that executes the **CancelMibChangeNotify2** function cannot own a resource on which the thread that executes a notification callback operation would wait because it would result in a similar deadlock. The **CancelMibChangeNotify2** function should be called from a different thread, on which the thread that receives the notification callback doesn’t have dependencies on.

The Teredo client also uses static UDP port 3544 for listening to multicast traffic sent on multicast IPv4 address 224.0.0.253 as defined in RFC 4380. For more information, see [http://www.ietf.org/rfc/rfc4380.txt](https://www.ietf.org/rfc/rfc4380.txt).

The **NotifyTeredoPortChange** function is used primarily by firewall applications in order to configure the appropriate exceptions to allow incoming and outgoing Teredo traffic.

The [NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable) function is used primarily by applications that use the Teredo client.

## See also

[CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2)

[GetTeredoPort](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getteredoport)

[NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable)