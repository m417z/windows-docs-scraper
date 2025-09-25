# RtmGetChangeStatus function

## Description

The
**RtmGetChangeStatus** function checks whether there are pending changes that have not been retrieved with
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NotifyHandle` [in]

Handle to a change notification.

### `DestHandle` [in]

Handle to the destination for which to return change status.

### `ChangeStatus` [out]

On input, *ChangeStatus* is a pointer to a **BOOL** value.

On output, *ChangeStatus* receives either **TRUE** or **FALSE** to indicate if the destination specified by *DestHandle* has a change notification pending.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

This function can be used to make portions of the client code more efficient. For example, a client may postpone some operation if there are changes that the client has not yet processed.

This function can also be used to monitor change notification in another thread.

## See also

[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmIgnoreChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmignorechangeddests)

[RtmIsMarkedForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmismarkedforchangenotification)

[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)