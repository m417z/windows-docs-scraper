# MprAdminAcceptReauthenticationEx function

## Description

Remote Access Service (RAS) calls the
**MprAdminAcceptReauthenticationEx** function whenever the quarantine state
of the client changes. **MprAdminAcceptReauthenticationEx** determines whether the user is allowed to reauthenticate and connect after the quarantine state has changed.

## Parameters

### `pRasConn` [in]

A pointer to a
[RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structure that describes this connection.

## Return value

If
**MprAdminAcceptReauthenticationEx** accepts the connection, the return value should be **TRUE**.

If
**MprAdminAcceptReauthenticationEx** rejects the connection, the return value should be **FALSE**.

## See also

[MprAdminAcceptReauthentication](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthentication)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)