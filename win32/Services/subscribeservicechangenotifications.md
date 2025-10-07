# SubscribeServiceChangeNotifications function

Subscribes for service status change notifications using a callback function.

## Parameters

*hService* \[in\]

A handle to the service or a handle to the service control manager (SCM) to monitor for changes.

Handles to services are returned by the [**OpenService**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-openservicea) and [**CreateService**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-createservicea) function and must have the **SERVICE\_QUERY\_STATUS** access right. Handles to the service control manager are returned by the [**OpenSCManager**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-openscmanagera) function and must have the **SC\_MANAGER\_ENUMERATE\_SERVICE** access right.

*eEventType* \[in\]

Specifies the type of status changes that should be reported. This parameter is set to one of the values specified in [**SC\_EVENT\_TYPE**](https://learn.microsoft.com/windows/win32/services/sc-event-type). The behavior for this function is different depending on the event type as follows.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
|

**SC\_EVENT\_DATABASE\_CHANGE**

0

| A service has been added or deleted. The *hService* parameter must be a handle to the SCM.<br> |
|

**SC\_EVENT\_PROPERTY\_CHANGE**

1

| One or more service properties have been updated. The *hService* parameter must be a handle to the service.<br> |
|

**SC\_EVENT\_STATUS\_CHANGE**

2

| The status of a service has changed. The *hService* parameter must be a handle to the service.<br> |

*pCallback* \[in\]

Specifies the callback function. The callback must be defined as having a type of **SC\_NOTIFICATION\_CALLBACK**. For more information, see Remarks.

*pCallbackContext* \[in, optional\]

A pointer representing the context for this notification callback.

*pSubscription* \[out\]

Returns a pointer to the subscription resulting from the notification callback registration. The caller is responsible for calling [**UnsubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/unsubscribeservicechangenotifications) to stop receiving notifications.

## Return value

If the function succeeds, the return value is **ERROR\_SUCCESS**.

If the function fails, the return value is one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The callback function is declared as follows:

```C++
typedef VOID CALLBACK SC_NOTIFICATION_CALLBACK(
    _In_    DWORD                   dwNotify,
    _In_    PVOID                   pCallbackContext
);
typedef SC_NOTIFICATION_CALLBACK* PSC_NOTIFICATION_CALLBACK;
```

The callback function receives a pointer to the context provided by the caller. The callback is invoked as a result of the service status change event. When the callback is invoked, it is provided with a bitmask of **SERVICE\_NOTIFY\_*XXX*** values that indicating the type of service status change. When the callback is provided with zero instead of a valid **SERVICE\_NOTIFY\_*XXX*** value, the application must verify what was changed.

The callback function must not block execution. If you expect the execution of the callback function to take time, offload the work that you perform in the callback function to a separate thread by queuing a work item to a thread in a thread pool. Some types of work that can make the callback function take time include performing file I/O, waiting on an event, and making external remote procedure calls.

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

[**UnsubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/unsubscribeservicechangenotifications)

[**QueryServiceDynamicInformation**](https://learn.microsoft.com/windows/desktop/api/Winsvc/nf-winsvc-queryservicedynamicinformation)

