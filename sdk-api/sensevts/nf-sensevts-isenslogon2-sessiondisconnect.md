# ISensLogon2::SessionDisconnect

## Description

The
**SessionDisconnect** method is used to disconnect from a Fast User Switching session or a Remote Desktop Connection. This is different from logging off from a session, because when you use this method the session is disconnected.

## Parameters

### `bstrUserName` [in]

The name of a current user.

### `dwSessionId` [in]

The session identifier of a session.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method returns successfully. |

## Remarks

SENS calls this method to notify an application that a session is disconnected.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[ISensLogon2](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon2)

[ISensLogon::Logoff](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-logoff)

[Terminal Services](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-portal)