# RtmReleaseChangedDests function

## Description

The
**RtmReleaseChangedDests** function releases the changed destination handles.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NotifyHandle` [in]

Handle to a change notification, obtained from a previous call to
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification).

### `NumDests` [in]

Specifies the number of destinations in *ChangedDests*.

### `ChangedDests` [in]

Pointer to an array of
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures to release. The changed destinations were obtained from a prior call to
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Always use this function to release changed
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures obtained from a call to
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

The
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure is a variable-sized structure. If a destination contains information for more than one view, the size of
**RTM_DEST_INFO** increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how large a *ChangedDests* buffer to allocate before calling this function.

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RtmGetChangeStatus](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangestatus)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmIgnoreChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmignorechangeddests)

[RtmIsMarkedForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmismarkedforchangenotification)

[RtmMarkDestForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmmarkdestforchangenotification)