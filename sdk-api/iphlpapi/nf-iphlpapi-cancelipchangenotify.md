# CancelIPChangeNotify function

## Description

The **CancelIPChangeNotify** function cancels notification of IPv4 address and route changes previously requested with successful calls to the [NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange) or [NotifyRouteChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyroutechange) functions.

## Parameters

### `notifyOverlapped` [in]

A pointer to the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure used in the previous call to [NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange) or [NotifyRouteChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyroutechange).

## Remarks

The
**CancelIPChangeNotify** function deregisters for a change notification previously requested for IPv4 address or route changes on a local computer. These requests to register for notification are made by calling the [NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange) or [NotifyRouteChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyroutechange) functions.

The [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure used in the previous call to one of these notification functions is passed to **CancelIPChangeNotify** function in the *notifyOverlapped* parameter to deregister for notifications.

The **CancelIPChangeNotify** can return **FALSE** if no notification request was found or an invalid *notifyOverlapped* parameter was passed.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange)

[NotifyRouteChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyroutechange)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)