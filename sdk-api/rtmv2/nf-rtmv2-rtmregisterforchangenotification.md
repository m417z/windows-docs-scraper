# RtmRegisterForChangeNotification function

## Description

The
**RtmRegisterForChangeNotification** function informs the routing table manager that the client should receive change notifications for the specified types of changes. The routing table manager returns a change notification handle, which the client must use when requesting change information after receiving a change notification message.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `TargetViews` [in]

Specifies the views in which to register for change notification.

### `NotifyFlags` [in]

Specifies the flags that indicate the type of changes for which the client requests notification. The following flags are used. (The flags are to be joined using a logical OR.)

| Constant | Meaning |
| --- | --- |
| **RTM_CHANGE_TYPE_ALL** | Notify the client of any change to a destination. |
| **RTM_CHANGE_TYPE_BEST** | Notify the client of changes to the current best route, or when the best route changes. |
| **RTM_CHANGE_TYPE_FORWARDING** | Notify the client of any best route changes that affect forwarding, such as next hop changes. |
| **RTM_NOTIFY_ONLY_MARKED_DESTS** | Notify the client of changes to destinations that the client has marked. If this flag is not specified, change notification messages for all destinations are sent. |

### `NotifyContext` [in]

Specifies the notification context that the
[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback) uses to indicate new changes. The notification context is the *Context2* parameter of the
**RTM_EVENT_CALLBACK** callback.

### `NotifyHandle` [out]

Receives a handle to a change notification. The handle must be used when calling
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are not enough available system resources to complete this operation. The routing table manager has exceeded the maximum number of change notifications that can be cached. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |
| **ERROR_NOT_SUPPORTED** | One or more of the specified views is not supported. |

## Remarks

A client calls
[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification) when it is registering for changes to a specific destination.

The routing table manager uses the
[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback) callback, specified when the client called
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity), to notify the client when changes have occurred; the client must call
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests) to receive the actual change information.

For sample code using this function, see
[Register For Change Notification](https://learn.microsoft.com/windows/desktop/RRAS/register-for-change-notification).

## See also

[RtmDeregisterFromChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmderegisterfromchangenotification)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification)