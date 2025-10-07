# NotifyStableUnicastIpAddressTable function

The **NotifyStableUnicastIpAddressTable** function retrieves the stable unicast IP address table on a local computer.

## Parameters

- *Family* \[in\]
The address family to retrieve.

 Possible values for the address family are listed in the Winsock2.h header file. Note that the values for the AF\_ address family and PF\_ protocol family constants are identical (for example, AF\_INET and PF\_INET), so you can use either constant.

 On Windows Vista and later versions of the Windows operating systems, possible values for the *Family* parameter are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Netioapi.h and you should never use Ws2def.h directly.

 The following values are currently supported for the address family:

    - AF\_INET
The IPv4 address family. When this value is specified, the function retrieves the stable unicast IP address table that contains only IPv4 entries.

    - AF\_INET6
The IPv6 address family. When this value is specified, the function retrieves the stable unicast IP address table that contains only IPv6 entries.

    - AF\_UNSPEC
The address family is unspecified. When this value is specified, the function retrieves the stable unicast IP address table that contains both IPv4 and IPv6 entries.

- *Table* \[out\]
A pointer to a [**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table) structure. When **NotifyStableUnicastIpAddressTable** is successful, this parameter returns the stable unicast IP address table on the local computer.

 When **NotifyStableUnicastIpAddressTable** returns ERROR\_IO\_PENDING, which indicates that the I/O request is pending, the stable unicast IP address table is returned to the function in the *CallerCallback* parameter.

- *CallerCallback* \[in\]
A pointer to the function to call with the stable unicast IP address table. This function is called if **NotifyStableUnicastIpAddressTable** returns ERROR\_IO\_PENDING, which indicates that the I/O request is pending.

- *CallerContext* \[in\]
A user context that is passed to the callback function that is specified in the *CallerCallback* parameter when the stable unicast IP address table is available.

- *NotificationHandle* \[in, out\]
A pointer that is used to return a handle that your driver can use to cancel the request to retrieve the stable unicast IP address table. This parameter is returned if the return value from **NotifyStableUnicastIpAddressTable** is ERROR\_IO\_PENDING, which indicates that the I/O request is pending.

## Return value

**NotifyStableUnicastIpAddressTable** returns STATUS\_SUCCESS and the stable unicast IP table is returned in the *Table* parameter if the function succeeds immediately.

If the I/O request is pending, the function returns ERROR\_IO\_PENDING and the function that the *CallerCallback* parameter points to is called when the I/O request has completed with the stable unicast IP address table.

If the function fails, **NotifyStableUnicastIpAddressTable** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An internal error occurred where an invalid handle was encountered. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Table* parameter was a **NULL** pointer, the *NotificationHandle* parameter was a **NULL** pointer, or the *Family* parameter was not either AF_INET, AF_INET6, or AF_UNSPEC. |
| **STATUS_NOT_ENOUGH_MEMORY** | There was insufficient memory. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

All unicast IP addresses, except dial-on-demand addresses, are considered stable only if they are in the preferred state. For a normal unicast IP address entry, this state would correspond to a **DadState** member of the [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) for the IP address that is set to **IpDadStatePreferred**. Every dial-on-demand address defines its own stability metric. Currently the only dial-on-demand address that the **NotifyStableUnicastIpAddressTable** function considers is the unicast IP address that the Teredo client uses on the local computer.

Your driver must set the *Family* parameter to either AF\_INET, AF\_INET6, or AF\_UNSPEC.

When **NotifyStableUnicastIpAddressTable** is successful and returns STATUS\_SUCCESS, the *Table* parameter returns the stable unicast IP address table on the local computer.

When **NotifyStableUnicastIpAddressTable** returns ERROR\_IO\_PENDING, which indicates that the I/O request is pending, the stable unicast IP address table is returned to the function in the *CallerCallback* parameter.

If the unicast IP address that Teredo uses is available on the local computer but not in the stable (qualified) state, **NotifyStableUnicastIpAddressTable** returns ERROR\_IO\_PENDING and the stable unicast IP address table is eventually returned by calling the function in the *CallerCallback* parameter. If the Teredo address is not available or is in the stable state and the other unicast IP addresses are in a stable state, the function in the *CallerCallback* parameter is never called.

The callback function that is specified in the *CallerCallback* parameter should be defined as a function of type **VOID**. The parameters that are passed to the callback function include the following.

| Parameter | Description |
| --- | --- |
| IN PVOID *CallerContext* | The *CallerContext* parameter that is passed to the **NotifyStableUnicastIpAddressTable** function when it is registering the driver for notifications. |
| IN PMIB_UNICASTIPADDRESS_TABLE *AddressTable* | A pointer to a [**MIB_UNICASTIPADDRESS_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table) structure that contains the stable unicast IP address table on the local computer. |

The **NotifyStableUnicastIpAddressTable** function is used primarily by drivers that use the Teredo client.

To cancel the notification after the callback is complete, call the [**CancelMibChangeNotify2**](https://learn.microsoft.com/windows-hardware/drivers/network/cancelmibchangenotify2) function, passing the *NotificationHandle* parameter that **NotifyStableUnicastIpAddressTable** returns.

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

[**CreateUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createunicastipaddressentry)

[**DeleteUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteunicastipaddressentry)

[**GetTeredoPort**](https://learn.microsoft.com/windows-hardware/drivers/network/getteredoport)

[**GetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddressentry)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**InitializeUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeunicastipaddressentry)

[**MIB\_NOTIFICATION\_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-notification-type)

[**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row)

[**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table)

[**NotifyTeredoPortChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyteredoportchange)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)

[**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry)