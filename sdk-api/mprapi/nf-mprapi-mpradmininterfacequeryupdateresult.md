# MprAdminInterfaceQueryUpdateResult function

## Description

The
**MprAdminInterfaceQueryUpdateResult** function returns the result of the last request to a specified router manager to update its routes for an interface. For more information, see
[MprAdminInterfaceUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceupdateroutes).

## Parameters

### `hMprServer` [in]

Handle to the router from which information is being retrieved. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. This handle is obtained from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwProtocolId` [in]

A **DWORD** value that specifies which router manager is being queried. The router uses a different router manager for each transport protocol. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `lpdwUpdateResult` [out]

Pointer to a **DWORD** variable. This variable receives the result of the last call to
[MprAdminInterfaceUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceupdateroutes).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INTERFACE_NOT_CONNECTED** | The specified interface is not connected; the result of the last update is no longer available. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *lpdwUpdateResult* parameter is **NULL**. |
| **ERROR_NO_SUCH_INTERFACE** | The specified transport is not running on the specified interface. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwProtocolId* value does not match any supported router manager. |

## Remarks

The *dwProtocolId* parameter specifies both a transport and a router manager, since the router maintains a router manager for each transport.

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceupdateroutes)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)