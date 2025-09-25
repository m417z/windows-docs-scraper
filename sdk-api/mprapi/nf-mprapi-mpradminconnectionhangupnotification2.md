# MprAdminConnectionHangupNotification2 function

## Description

Remote Access Service calls the
**MprAdminConnectionHangupNotification2** function after the last link for the specified connection has been dismantled.

## Parameters

### `pRasConnection0` [in]

Pointer to a
[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0) structure that describes this connection.

### `pRasConnection1` [in]

Pointer to the
[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1) structure that describes this connection.

### `pRasConnection2` [in]

Pointer to a
[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2) structure that describes this connection.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of the
**MprAdminConnectionHangupNotification2** function in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

**Windows 2000 Server and earlier:** If
**MprAdminAcceptNewConnection** does not accept the new connection, RAS does not call the
**MprAdminConnectionHangupNotification2** function.

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminConnectionHangupNotification2**. Calls to these functions do not return when made from within a callout function.

## See also

[MprAdminAcceptNewConnection2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection)

[MprAdminAcceptNewLink](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewlink)

[MprAdminConnectionHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification)

[MprAdminConnectionHangupNotification3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification3)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)