# CancelMibChangeNotify2 function

## Description

The **CancelMibChangeNotify2** function deregisters for change notifications for IP interface changes, IP address changes, IP route changes, Teredo port changes, and when the unicast IP address table is stable and can be retrieved.

## Parameters

### `NotificationHandle` [in]

The handle returned from a notification
registration or retrieval function to indicate which notification to cancel.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *NotificationHandle* parameter was a **NULL** pointer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **CancelMibChangeNotify2** function is defined on Windows Vista and later.

The
**CancelMibChangeNotify2** function deregisters for a change notification previously requested for IP interface changes, IP address changes, IP route changes, or Teredo port changes on a local computer. These requests are made by calling [NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange), [NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange), [NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2), or [NotifyTeredoPortChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyteredoportchange). The
**CancelMibChangeNotify2** function also cancels a previous request to be notified when the unicast IP address table is stable on a local computer and can be retrieved. This request is made by calling the [NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable) function.

The *NotificationHandle* parameter returned to these notification functions is passed to **CancelMibChangeNotify2** to deregister for notifications or cancel a pending request to retrieve the stable unicast IP address table.

An application cannot make a call to the **CancelMibChangeNotify2** function from the context of the thread which is currently executing the notification callback function for the same *NotificationHandle* parameter. Otherwise, the thread executing that callback will result in deadlock. So the **CancelMibChangeNotify2** function must not be called directly as part of the notification callback routine. In a more general situation, a thread that executes the **CancelMibChangeNotify2** function cannot own a resource on which the thread that executes a notification callback operation would wait because it would result in a similar deadlock. The **CancelMibChangeNotify2** function should be called from a different thread, on which the thread that receives the notification callback doesn’t have dependencies on.

## See also

[NotifyIpInterfaceChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyipinterfacechange)

[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2)

[NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable)

[NotifyTeredoPortChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyteredoportchange)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)