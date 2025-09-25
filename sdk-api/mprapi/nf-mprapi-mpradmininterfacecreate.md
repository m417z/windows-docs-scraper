# MprAdminInterfaceCreate function

## Description

The
**MprAdminInterfaceCreate** function creates an interface on a specified server.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lpBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, 2, and 3, as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | [MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) |
| 1 | [MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1) |
| 2 | [MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) |
| 3 | Windows Server 2008 or later: [MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3) |

### `lpbBuffer` [in]

A pointer to a
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0),
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1),
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2), or [MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3) structure. The *dwLevel* parameter indicates the type of structure.

### `phInterface` [out]

Pointer to a **HANDLE** variable. The variable receives a handle to use in all subsequent calls to manage this interface.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The router interface type is not supported because the Dynamic Interface Manager is configured to run only on a LAN. |
| **ERROR_INTERFACE_ALREADY_EXISTS** | An interface with the same name already exists. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* value is invalid. |

## Remarks

The
**MprAdminInterfaceCreate** function supports the
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) structure. However,
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate) does not. In order to create a demand-dial interface that is persistent after a reboot, call
**MprAdminInterfaceCreate** with
**MPR_INTERFACE_2**, then call
**MprConfigInterfaceCreate** with
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) or
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1).

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)

[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2)

[MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3)

[MprAdminInterfaceDelete](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedelete)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)