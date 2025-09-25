# ISensLogon2::PostShell

## Description

Use the
**PostShell** method when a user has logged on and Windows Explorer is running. This method is different from the
[Logon](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon2-logon) method because
**Logon** is called after logon when the Shell may not yet be running.

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

SENS calls this method to notify your application that a user has logged on and the Windows Explorer (Shell) is running.

## See also

[About System Event Notification Service](https://learn.microsoft.com/windows/desktop/Sens/about-system-event-notification-service)

[ISensLogon2](https://learn.microsoft.com/windows/desktop/api/sensevts/nn-sensevts-isenslogon2)

[ISensLogon::Logoff](https://learn.microsoft.com/windows/desktop/api/sensevts/nf-sensevts-isenslogon-logoff)

[Terminal Services](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-portal)