# MprAdminLinkHangupNotification function

## Description

RAS calls the
**MprAdminLinkHangupNotification** function whenever a link for a particular connection is dismantled.

## Parameters

### `pRasPort0` [in]

Pointer to a
[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0) structure that describes the port being used by the link.

### `pRasPort1` [in]

Pointer to a
[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1) structure that describes the port being used by the link.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of
**MprAdminLinkHangupNotification** in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

**Windows 2000 Server and earlier:** If RAS does not accept the new link, RAS does not call the
**MprAdminLinkHangupNotification** function.

Do not call any of the
[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions) or
[RAS User Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-administration-functions) from inside
**MprAdminLinkHangupNotification**. Calls to these functions will not return when made from within a callout function.

## See also

[MprAdminAcceptNewConnection](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection)

[MprAdminAcceptNewConnection2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewconnection2)

[MprAdminAcceptNewLink](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptnewlink)

[MprAdminConnectionHangupNotification](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification)

[MprAdminConnectionHangupNotification2](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification2)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0)

[RAS_PORT_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_1)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)