# NotifyStableUnicastIpAddressTable function

## Description

The
**NotifyStableUnicastIpAddressTable** function retrieves the stable unicast IP address table on a local computer.

## Parameters

### `Family` [in]

The address family to retrieve.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, the function retrieves the stable unicast IP address table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, the function retrieves the stable unicast IP address table containing only IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, the function retrieves the stable unicast IP address table containing only IPv6 entries. |

### `Table` [in, out]

A pointer to a
[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) structure. When **NotifyStableUnicastIpAddressTable** is successful, this parameter returns the stable unicast IP address table on the local computer.

When **NotifyStableUnicastIpAddressTable** returns **ERROR_IO_PENDING** indicating that the I/O request is pending, then the stable unicast IP address table is returned to the function in the *CallerCallback* parameter.

### `CallerCallback` [in]

A pointer to the function to call with the stable unicast IP address table. This function will be invoked
if **NotifyStableUnicastIpAddressTable** returns **ERROR_IO_PENDING**, indicating that the I/O request is pending.

### `CallerContext` [in]

A user context passed to the callback function specified in the *CallerCallback* parameter when the stable unicast IP address table si available.

### `NotificationHandle` [in, out]

A pointer used to return a handle that can be used to
cancel the request to retrieve the stable unicast IP address table. This parameter is returned if the return value from **NotifyStableUnicastIpAddressTable** is **ERROR_IO_PENDING** indicating that the I/O request is pending.

## Return value

If the function succeeds immediately, the return value is NO_ERROR and the stable unicast IP table is returned in the *Table* parameter.

If the I/O request is pending, the function returns **ERROR_IO_PENDING** and the function pointed to by the *CallerCallback* parameter is called when the I/O request has completed with the stable unicast IP address table.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Table* parameter was a **NULL** pointer, the *NotificationHandle* parameter was a **NULL** pointer, or the *Family* parameter was not either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **NotifyStableUnicastIpAddressTable** function is defined on Windows Vista and later.

If the **NotifyStableUnicastIpAddressTable** function succeeds immediately, the return value is NO_ERROR and the stable unicast IP table is returned in the *Table* parameter. The calling application should free the memory pointed to by the *Table* parameter using the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable) function when the [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) information is no longer needed.

All unicast IP addresses except dial-on-demand addresses are considered stable only if they are in the preferred state. For a normal unicast IP address entry, this would correspond to a DadState member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) for the IP address set to **IpDadStatePreferred**.
Every dial-on-demand address defines its own stability metric. Currently the only dial-on-demand address considered by this function is the unicast IP address used by the Teredo client on the local computer.

The *Family* parameter must be set to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

When **NotifyStableUnicastIpAddressTable** is successful and returns NO_ERROR, the *Table* parameter returns the stable unicast IP address table on the local computer.

When **NotifyStableUnicastIpAddressTable** returns **ERROR_IO_PENDING** indicating that the I/O request is pending, then the stable unicast IP address table is returned to the function in the *CallerCallback* parameter.

The **NotifyStableUnicastIpAddressTable** function is used primarily by applications that use the Teredo client.

If the unicast IP address used by Teredo is available on the local computer but not in the stable (qualified) state, **NotifyStableUnicastIpAddressTable** returns ERROR_IO_PENDING and the stable unicast IP address table is eventually returned by calling the function in the *CallerCallback* parameter. If the Teredo address is not available or is in the stable state and the other unicast IP addresses are in a stable state, then the function in the *CallerCallback* parameter will never be invoked.

The callback function specified in the *CallerCallback* parameter should be defined as a function of type **VOID**. The parameters passed to the callback function include the following:

| Parameter | Description |
| --- | --- |
| IN PVOID CallerContext | The *CallerContext* parameter passed to the **NotifyStableUnicastIpAddressTable** function when registering for notifications. |
| IN PMIB_UNICASTIPADDRESS_TABLE AddressTable | A pointer to a [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) containing the stable unicast IP address table on the local computer. |

The callback function specified in the *CallerCallback* parameter must be implemented in the same process as the application calling the **NotifyStableUnicastIpAddressTable** function. If the callback function is in a separate DLL, then the DLL should be loaded before calling the **NotifyStableUnicastIpAddressTable** function to register for change notifications.

The memory pointed to by the *AddressTable* parameter used in a callback indication is allocated by the operating system. An application that receives a notification should free the memory pointed to by the *AddressTable* parameter using the [FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable) function when the [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) information is no longer needed.

Once the **NotifyStableUnicastIpAddressTable** function is called to register for change notifications, these notifications will continue to be sent until the application deregisters for change notifications or the application terminates. If the application terminates, the system will automatically deregister any registration for change notifications. It is still recommended that an application explicitly deregister any change notifications before it terminates.

Any registration for change notifications does not persist if the system is shutdown or rebooted.

To deregister for change notifications, call the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function passing the *NotificationHandle* parameter returned by **NotifyStableUnicastIpAddressTable**.

An application cannot make a call to the [CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2) function from the context of the thread which is currently executing the notification callback function for the same *NotificationHandle* parameter. Otherwise, the thread executing that callback will result in deadlock. So the **CancelMibChangeNotify2** function must not be called directly as part of the notification callback routine. In a more general situation, a thread that executes the **CancelMibChangeNotify2** function cannot own a resource on which the thread that executes a notification callback operation would wait because it would result in a similar deadlock. The **CancelMibChangeNotify2** function should be called from a different thread, on which the thread that receives the notification callback doesn’t have dependencies on.

## See also

[CancelMibChangeNotify2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-cancelmibchangenotify2)

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteunicastipaddressentry)

[FreeMibTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-freemibtable)

[GetTeredoPort](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getteredoport)

[GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry)

[MIB_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/netioapi/ne-netioapi-mib_notification_type)

[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[NotifyTeredoPortChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyteredoportchange)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)

[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setunicastipaddressentry)