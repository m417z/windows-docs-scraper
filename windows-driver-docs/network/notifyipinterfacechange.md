# NotifyIpInterfaceChange function

The **NotifyIpInterfaceChange** function registers the driver to be notified for changes to all IP interfaces, IPv4 interfaces, or IPv6 interfaces on a local computer.

## Parameters

- *Family* \[in\]
The address family to register the driver for change notifications on.

 Possible values for the address family are listed in the Winsock2.h header file. Note that the values for the AF\_ address family and PF\_ protocol family constants are identical (for example, AF\_INET and PF\_INET), so you can use either constant.

 On Windows Vista and later versions of the Windows operating systems, possible values for the *Family* parameter are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Netioapi.h and you should never use Ws2def.h directly.

 The following values are currently supported for the address family:

    - AF\_INET
The IPv4 address family. When this value is specified, this function registers the driver to be notified only for IPv4 change notifications.

    - AF\_INET6
The IPv6 address family. When this value is specified, this function registers the driver for only IPv6 change notifications.

    - AF\_UNSPEC
The address family is unspecified. When this value is specified, this function registers the driver to be notified for both IPv4 and IPv6 changes.

- *Callback* \[in\]
A pointer to the function to call when a change occurs. This function is called when an interface notification is received.

- *CallerContext* \[in\]
A user context that is passed to the callback function that is specified in the *Callback* parameter when an interface notification is received.

- *InitialNotification* \[in\]
A value that indicates whether the callback should be invoked immediately after registration for change notification completes. This initial notification does not indicate a change occurred to an IP interface. The purpose of this parameter to provide confirmation that the callback is registered.

- *NotificationHandle* \[in, out\]
A pointer used to return a handle that can be later used to deregister the change notification. On success, a notification handle is returned in this parameter. If an error occurs, **NULL** is returned.

## Return value

**NotifyIpInterfaceChange** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **NotifyIpInterfaceChange** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Family* parameter was not either AF_INET, AF_INET6, or AF_UNSPEC. |
| **STATUS_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

Your driver must set the *Family* parameter to either AF\_INET, AF\_INET6, or AF\_UNSPEC.

The invocation of the callback function that is specified in the *Callback* parameter is serialized. The callback function should be defined as a function of type **VOID**. The parameters that are passed to the callback function include the following.

| Parameter | Description |
| --- | --- |
| IN PVOID *CallerContext* | The *CallerContext* parameter that is passed to the **NotifyIpInterfaceChange** function when it is registering the driver for change notifications. |
| IN PMIB_IPINTERFACE_ROW *Row* OPTIONAL | A pointer to the [**MIB_IPINTERFACE_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) entry for the interface that was changed. This parameter is a **NULL** pointer when the [**MIB_NOTIFICATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type) value that is passed in the *NotificationType* parameter to the callback function is set to **MibInitialNotification**. This situation can occur only if the *InitialNotification* parameter that is passed to **NotifyIpInterfaceChange** was set to **TRUE** when registering the driver for change notifications. |
| IN MIB_NOTIFICATION_TYPE *NotificationType* | The notification type. This member can be one of the values from the [**MIB_NOTIFICATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type) enumeration type. |

To deregister the driver for change notifications, call the [**CancelMibChangeNotify2**](https://learn.microsoft.com/windows-hardware/drivers/network/cancelmibchangenotify2) function, passing the *NotificationHandle* parameter that **NotifyIpInterfaceChange** returns.

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

[**GetIfEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getifentry2)

[**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable)

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry)

[**InitializeIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeipinterfaceentry)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)

[**MIB\_IF\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-table2)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**MIB\_NOTIFICATION\_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type)

[**SetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setipinterfaceentry)