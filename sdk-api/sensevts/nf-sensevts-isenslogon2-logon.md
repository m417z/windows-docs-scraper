# ISensLogon2::Logon

## Description

The
**Logon** method notifies an application that a user is logged on.

## Parameters

### `bstrUserName` [in]

The name of a user who is logged on.

### `dwSessionId` [in]

The session identifier of a session.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returns successfully. |

## Remarks

SENS calls this method to notify an application that a user is logged on.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[ISensLogon2](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon2)

[ISensLogon::Logon](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-logon)

[Terminal Services](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-portal)