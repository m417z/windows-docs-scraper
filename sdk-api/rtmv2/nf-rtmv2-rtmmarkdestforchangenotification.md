# RtmMarkDestForChangeNotification function

## Description

The
**RtmMarkDestForChangeNotification** function marks a destination for a client. A marked destination indicates to the routing table manager that it should send the client change notification messages for the marked destination. The client receives change notification messages when a destination changes. The change notifications inform the client of changes to best-route information for the specified destination. This function should be used when
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification) is called to request changes for specific destinations (RTM_NOTIFY_ONLY_MARKED_DESTS).

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NotifyHandle` [in]

Handle to a change notification obtained via a previous call to
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification).

### `DestHandle` [in]

Handle to the destination that the client is marking for notification of changes.

### `MarkDest` [in]

Specifies whether to mark a destination and receive change notifications. Specify **TRUE** to mark a destination and start receive change notifications for the specified destination. Specify **FALSE** to stop receiving change notifications a previously marked destination.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmGetChangeStatus](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangestatus)

[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests)

[RtmIgnoreChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmignorechangeddests)

[RtmIsMarkedForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmismarkedforchangenotification)

[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)