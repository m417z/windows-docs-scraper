# RtmGetChangedDests function

## Description

The
**RtmGetChangedDests** function returns a set of destinations with changed information.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NotifyHandle` [in]

Handle to a change notification obtained from a previous call to
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification).

### `NumDests` [in, out]

On input, *NumDests* is a pointer to a **UINT** value that specifies the maximum number of destinations that can be received by *ChangedDests*.

On output, *NumDests* receives the actual number of destinations received by *ChangedDests*.

### `ChangedDests` [out]

On input, *ChangedDests* is a pointer to an array of
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures.

On output, *ChangedDests* is filled with the changed destination information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NO_MORE_ITEMS** | No more changed destinations to retrieve. |

## Remarks

A client is notified of changes by an
[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback). The
**RTM_EVENT_CALLBACK** is only used to notify the client, not deliver the changes. After a change notification is received, the client must call
**RtmGetChangedDests** repeatedly to retrieve all the changes.

If two or more changes to the same destination have occurred since the notification, only the latest change is returned.

When a client no longer needs the handles in *ChangedDests*, the client must use
[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests) to release the handles.

For sample code using this function, see
[Use the Event Notification Callback](https://learn.microsoft.com/windows/desktop/RRAS/use-the-event-notification-callback).

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback)

[RtmGetChangeStatus](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangestatus)

[RtmIgnoreChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmignorechangeddests)

[RtmIsMarkedForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmismarkedforchangenotification)

[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)