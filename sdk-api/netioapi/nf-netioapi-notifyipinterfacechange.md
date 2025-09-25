# NotifyIpInterfaceChange function

## Description

The
**NotifyIpInterfaceChange** function registers to be notified for changes to all IP interfaces, IPv4 interfaces, or IPv6 interfaces on a local computer.

## Parameters

### `Family` [in]

The address family on which to register for change notifications.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, this function registers for both IPv4 and IPv6 change notifications. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function register for only IPv4 change notifications. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function registers for only IPv6 change notifications. |

### `Callback` [in]

A pointer to the function to call when a change occurs. This function will be invoked
when an interface notification is received.

### `CallerContext` [in]

A user context passed to the callback function specified in the *Callback* parameter when an interface notification is received.

### `InitialNotification` [in]

A value that indicates whether the callback should be invoked
immediately after registration for change notification completes. This initial notification does not indicate a change occurred to an IP interface. The purpose of this parameter to provide confirmation that the callback is registered.

### `NotificationHandle` [in, out]

A pointer used to return a handle that can be later used to
deregister the change notification. On success, a notification handle is returned in this parameter. If an error occurs, **NULL** is returned.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Family* parameter was not either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **NotifyIpInterfaceChange** function is defined on Windows Vista and later.

The *Family* parameter must be set to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

The invocation of the callback function specified in the *Callback* parameter is serialized. The callback function should be defined as a function of type **VOID**. The parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID CallerContext | The *CallerContext* parameter passed to the **NotifyIpInterfaceChange** function when registering for notifications. |
| IN PMIB_IPINTERFACE_ROW Row OPTIONAL | A pointer to the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) entry for the interface that was changed. This parameter is a **NULL** pointer when the **MIB_NOTIFICATION_TYPE** value passed in the *NotificationType* parameter to the callback function is set to **MibInitialNotification**. This can only occur if the *InitialNotification* parameter passed to **NotifyIpInterfaceChange** was set to **TRUE** when registering for notifications. |
| IN MIB_NOTIFICATION_TYPE NotificationType | The notification type. This member can be one of the values from the [MIB_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/netioapi/ne-netioapi-mib_notification_type) enumeration type defined in the *Netioapi.h* header file. |

The callback function specified in the *Callback* parameter must be implemented in the same process as the application calling the **NotifyIpInterfaceChange** function. If the callback function is in a separate DLL, then the DLL should be loaded before calling the **NotifyIpInterfaceChange** function to register for change notifications.

When the callback function is received when a change occurs and the *Row* parameter is not **NULL**, the pointer to the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure passed in the *Row* parameter contains incomplete data. The information returned in the **MIB_IPINTERFACE_ROW** structure is only enough information that an application can call the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function to query complete information on the IP interface that changed. When the callback function is received, an application should allocate a **MIB_IPINTERFACE_ROW** structure and initialize it with the **Family**, **InterfaceLuid** and **InterfaceIndex** members in the **MIB_IPINTERFACE_ROW** structure pointed to by the *Row* parameter received. A pointer to this newly initialized **MIB_IPINTERFACE_ROW** structure should be passed to the **GetIpInterfaceEntry** function to retrieve complete information on the IP interface that was changed.

The memory pointed to by the *Row* parameter used in the callback indications is managed by the operating system. An application that receives a notification should never attempt to free the memory pointed to by the *Row* parameter.

To deregister for change notifications, call the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function passing the *NotificationHandle* parameter returned by **NotifyIpInterfaceChange**.

An application cannot make a call to the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function from the context of the thread which is currently executing the notification callback function for the same *NotificationHandle* parameter. Otherwise, the thread executing that callback will result in deadlock. So the **CancelMibChangeNotify2** function must not be called directly as part of the notification callback routine. In a more general situation, a thread that executes the **CancelMibChangeNotify2** function cannot own a resource on which the thread that executes a notification callback operation would wait because it would result in a similar deadlock. The **CancelMibChangeNotify2** function should be called from a different thread, on which the thread that receives the notification callback doesn’t have dependencies on.

Once the **NotifyIpInterfaceChange** function is called to register for change notifications, these notifications will continue to be sent until the application deregisters for change notifications or the application terminates. If the application terminates, the system will automatically deregister any registration for change notifications. It is still recommended that an application explicitly deregister for change notifications before it terminates.

Any registration for change notifications does not persist across a system shut down or reboot.

## See also

[CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2)

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeipinterfaceentry)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[MIB_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/netioapi/ne-netioapi-mib_notification_type)

[SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry)