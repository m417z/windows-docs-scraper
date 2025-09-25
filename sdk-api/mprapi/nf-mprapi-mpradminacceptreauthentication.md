# MprAdminAcceptReauthentication function

## Description

Remote Access Service calls the
**MprAdminAcceptReauthentication** function whenever the quarantine state
of the client changes. **MprAdminAcceptReauthentication** determines whether the user is allowed to reauthenticate and connect after the quarantine state has changed.

The quarantine state of a connection is determined by the Network Access Protection (NAP) agent, and is stored in the **rasQuarState** member of the [RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3) structure.

## Parameters

### `pRasConnection0` [in]

Pointer to a
[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0) structure that describes this connection.

### `pRasConnection1` [in]

Pointer to a
[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1) structure that describes this connection.

### `pRasConnection2` [in]

Pointer to a
[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2) structure that describes this connection.

### `pRasConnection3` [in]

Pointer to a
[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3) structure that describes this connection.

## Return value

If
**MprAdminAcceptReauthentication** accepts the connection, the return value should be **TRUE**.

If
**MprAdminAcceptReauthentication** rejects the connection, the return value should be **FALSE**.

## Remarks

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminAcceptReauthentication**. Calls to these functions do not return when made from within a callout function.

## See also

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)