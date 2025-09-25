# MprAdminInterfaceSetInfo function

## Description

The
**MprAdminInterfaceSetInfo** function sets information for a specified interface on a specified server.

## Parameters

### `hMprServer` [in]

Handle to the router to query. This handle is obtained from a previous call to
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface obtained by a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lpbBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, 2, and 3, as listed in the following table.

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

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* value is invalid. |

## Remarks

The
**MprAdminInterfaceSetInfo** function supports the
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) structure. However,
[MprConfigInterfaceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacesetinfo) does not. In order to make persistent changes to a demand-dial interface, call
**MprAdminInterfaceSetInfo** with
**MPR_INTERFACE_2**, then call
**MprConfigInterfaceSetInfo** with
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) or
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1).

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)

[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2)

[MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3)

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)