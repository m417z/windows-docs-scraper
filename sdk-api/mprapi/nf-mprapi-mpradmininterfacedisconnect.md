# MprAdminInterfaceDisconnect function

## Description

The
**MprAdminInterfaceDisconnect** function disconnects a connected WAN interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface. This handle is obtained from a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INTERFACE_NOT_CONNECTED** | This interface is not connected. Therefore, it cannot be disconnected. |

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference),
[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions),
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate),
[MprAdminInterfaceConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceconnect),
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)