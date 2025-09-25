# ISensLogon2::SessionReconnect

## Description

The session was reconnected. The
**SessionReconnect** method is used when you reconnect to a Fast User Switching session or a Remote Desktop Connection. This is different from logging on to a new session.

## Parameters

### `bstrUserName` [in]

Name of the current user.

### `dwSessionId` [in]

The session identifier of the session.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned successfully. |

## Remarks

SENS calls this method to notify your application that the session was reconnected.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[ISensLogon2](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon2)

[ISensLogon::Logoff](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-logoff)

[Terminal Services](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-portal)