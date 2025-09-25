# IRDPSRAPISharingSession2::SendControlLevelChangeResponse

## Description

Sends an [OnControlLevelChangeResponse](https://learn.microsoft.com/previous-versions/windows/desktop/rdp/oncontrollevelchangeresponse) event.

## Parameters

### `pAttendee` [in]

Attendee that requests control.

### `RequestedLevel` [in]

Level of control requested by the attendee. For possible values, see the [CTRL_LEVEL](https://learn.microsoft.com/windows/win32/api/rdpencomapi/ne-rdpencomapi-ctrl_level) enumeration.

### `ReasonCode` [in]

Specifies the reason for the change.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPISharingSession2](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapisharingsession2)