# CancelMibChangeNotify2 function

The **CancelMibChangeNotify2** function deregisters a driver change notification for IP interface changes, IP address changes, IP route changes, and requests to retrieve the stable Unicast IP address table.

## Parameters

- *NotificationHandle* \[in\]
The handle that is returned from a notification registration or retrieval function to indicate which notification to cancel.

## Return value

**CancelMibChangeNotify2** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **CancelMibChangeNotify2** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. **CancelMibChangeNotify2** returns this error if the *NotificationHandle* parameter was a **NULL** pointer. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **CancelMibChangeNotify2** function deregisters a driver change notification previously requested for IP interface changes, IP address changes, or IP route changes on a local computer. These requests are made by calling [**NotifyIpInterfaceChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyipinterfacechange), [**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2), or [**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange). The **CancelMibChangeNotify2** function also cancels a previous request to retrieve the stable unicast IP address table on a local computer. This request is made by calling the [**NotifyStableUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/notifystableunicastipaddresstable) function.

The *NotificationHandle* parameter that is returned to these notification functions is passed to **CancelMibChangeNotify2** to deregister driver change notifications or to cancel a pending request to retrieve the stable unicast IP address table.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | PASSIVE_LEVEL |

## See also

[**NotifyIpInterfaceChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyipinterfacechange)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**NotifyStableUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/notifystableunicastipaddresstable)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)