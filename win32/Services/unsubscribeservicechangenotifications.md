# UnsubscribeServiceChangeNotifications function

Unsubscribes from service status change notifications. This function uses subscriptions returned by [**SubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/subscribeservicechangenotifications).

## Parameters

*pSubscription* \[in\]

A pointer to the subscription to be unsubscribed.

## Return value

This function does not return a value.

## Remarks

**UnsubscribeServiceChangeNotifications** does not return until outstanding in-process callbacks are complete. So, you cannot call **UnsubscribeServiceChangeNotifications** within the callback without causing a deadlock.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Winsvcp.h |
| DLL<br> | SecHost.dll |

## See also

[**CreateService**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-createservicea)

[**OpenService**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-openservicea)

[**OpenSCManager**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-openscmanagera)

[**SubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/subscribeservicechangenotifications)

[**QueryServiceDynamicInformation**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-queryservicedynamicinformation)

