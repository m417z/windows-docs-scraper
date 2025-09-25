# RtmIgnoreChangedDests function

## Description

The
**RtmIgnoreChangedDests** function skips the next change for each destination if it has already occurred. This function can be used after
[RtmGetChangeStatus](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangestatus) to prevent the routing table manager returning this change in response to a call to
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NotifyHandle` [in]

Handle to a change notification.

### `NumDests` [in]

Specifies the number of destinations in *ChangedDests*.

### `ChangedDests` [in]

Pointer to an array of **RTM_DEST_HANDLE** handles that indicate the destinations for which to ignore any pending changes.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

When the destinations are no longer required, release them by calling
[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests).

## See also

[RtmGetChangeStatus](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangestatus)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmIsMarkedForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmismarkedforchangenotification)

[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)