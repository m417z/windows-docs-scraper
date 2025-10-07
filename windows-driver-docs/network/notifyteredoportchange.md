# NotifyTeredoPortChange function

The **NotifyTeredoPortChange** function registers the driver to be notified for changes to the UDP port number that the Teredo client uses for the Teredo service port on a local computer.

## Parameters

- *Callback* \[in\]
A pointer to the function to call when a Teredo client port change occurs. This function is called when a Teredo port change notification is received.

- *CallerContext* \[in\]
A user context that is passed to the callback function that is specified in the Callback parameter when a Teredo port change notification is received.

- *InitialNotification* \[in\]
A value that indicates whether the callback should be called immediately after registration for driver change notification completes. This initial notification does not indicate that a change occurred to the Teredo client port. This parameter provides confirmation that the callback is registered.

- *NotificationHandle* \[in, out\]
A pointer that is used to return a handle that your driver can later use to deregister the driver change notification. On success, a notification handle is returned in this parameter. If an error occurs, **NULL** is returned.

## Return value

**NotifyTeredoPortChange** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **NotifyTeredoPortChange** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Callback* parameter is a **NULL** pointer. |
| **STATUS_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The invocation of the callback function that is specified in the *Callback* parameter is serialized. The callback function should be defined as a function of type **VOID**. The parameters that are passed to the callback function include the following.

| Parameter | Description |
| --- | --- |
| IN PVOID *CallerContext* | The *CallerContext* parameter that is passed to the **NotifyTeredoPortChange** function when it is registering the driver for change notifications. |
| IN USHORT *Port* | The UDP port number that the Teredo client currently uses. This parameter is zero when the [**MIB_NOTIFICATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type) value that is passed in the *NotificationType* parameter to the callback function is set to **MibInitialNotification**. This situation can occur only if the *InitialNotification* parameter that is passed to **NotifyTeredoPortChange** was set to **TRUE** when registering the driver for change notifications. |
| IN MIB_NOTIFICATION_TYPE *NotificationType* | The notification type. This member can be one of the values from the [**MIB_NOTIFICATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type) enumeration type. |

Your driver can use the [**GetTeredoPort**](https://learn.microsoft.com/windows-hardware/drivers/network/getteredoport) function to retrieve the initial UDP port number that the Teredo client used for the Teredo service port.

The Teredo port is dynamic and can change any time that the Teredo client is restarted on the local computer. A driver can register to be notified when the Teredo service port changes by calling the **NotifyTeredoPortChange** function.

The Teredo client also uses static UDP port 3544 for listening to multicast traffic that is sent on multicast IPv4 address 224.0.0.253 as defined in RFC 4380. For more information, see [Teredo: Tunneling IPv6 over UDPthrough Network Address Translations (NATs)](https://go.microsoft.com/fwlink/p/?linkid=84066).

The **NotifyTeredoPortChange** function is used primarily by firewall drivers to configure the appropriate exceptions to enable incoming and outgoing Teredo traffic.

To deregister the driver for change notifications, call the [**CancelMibChangeNotify2**](https://learn.microsoft.com/windows-hardware/drivers/network/cancelmibchangenotify2) function, passing the *NotificationHandle* parameter that the **NotifyTeredoPortChange** function returns.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CancelMibChangeNotify2**](https://learn.microsoft.com/windows-hardware/drivers/network/cancelmibchangenotify2)

[**GetTeredoPort**](https://learn.microsoft.com/windows-hardware/drivers/network/getteredoport)

[**NotifyStableUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/notifystableunicastipaddresstable)