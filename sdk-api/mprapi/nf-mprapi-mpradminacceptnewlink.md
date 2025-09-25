# MprAdminAcceptNewLink function

## Description

Remote Access Service (RAS) calls the
**MprAdminAcceptNewLink** function each time a link is created for a particular connection. RAS calls this function once immediately after
[MprAdminAcceptNewConnection](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection) returns, and an additional time for every new link that is to be used with the connection.

## Parameters

### `pRasPort0` [in]

Pointer to a
[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0) structure that describes the port being used by the link.

### `pRasPort1` [in]

Pointer to a
[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1) structure that describes the port being used by the link.

## Return value

If RAS should accept the new link, the return value should be **TRUE**.

If RAS should not accept the new link, the return value should be **FALSE**.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of
**MprAdminAcceptNewLink** in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup). The remote-access user is allowed to connect only if the implementation of
**MprAdminAcceptNewLink** in each of the DLLs accepts the connection. In other words, every DLL must accept the link in order for the link to be established.

**Windows 2000 Server and earlier:** If RAS does not accept the new link, RAS does not call the
[MprAdminLinkHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminlinkhangupnotification) function.

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminAcceptNewLink**. Calls to these functions do not return when made from within a callout function.

## See also

[MprAdminAcceptNewConnection](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection)

[MprAdminConnectionHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification)

[MprAdminLinkHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminlinkhangupnotification)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0)

[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)