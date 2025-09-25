# MprAdminAcceptNewConnection3 function

## Description

Remote Access Service calls the
**MprAdminAcceptNewConnection3** function each time a new user dials in and successfully completes RAS authentication.
**MprAdminAcceptNewConnection3** determines whether the user is allowed to connect.

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
**MprAdminAcceptNewConnection3** accepts the connection, the return value should be **TRUE**.

If
**MprAdminAcceptNewConnection3** rejects the connection, the return value should be **FALSE**.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of the
**MprAdminAcceptNewConnection3** function in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup). The remote-access user is allowed to connect only if the implementation of
**MprAdminAcceptNewConnection3** in each of the DLLs accepts the connection. In other words, every DLL must accept the connection in order for the user to be allowed to connect.

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminAcceptNewConnection3**. Calls to these functions do not return when made from within a callout function.

## See also

[MprAdminAcceptNewConnection](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection)

[MprAdminAcceptNewConnection2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection2)

[MprAdminConnectionHangupNotification2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification2)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)