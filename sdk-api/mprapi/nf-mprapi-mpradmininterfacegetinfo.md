# MprAdminInterfaceGetInfo function

## Description

The
**MprAdminInterfaceGetInfo** function retrieves information for a specified interface on a specified server.

## Parameters

### `hMprServer` [in]

Handle to the router to query. This handle is obtained from a previous call to
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface obtained by a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is structured in the *lplpbBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, 2, and 3, as listed in the following table.

| Value | Structure Format |
| --- | --- |
| 0 | [MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) |
| 1 | [MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1) |
| 2 | [MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) |
| 3 | Windows Server 2008 or later: [MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3) |

Values of 1, 2, and 3 are valid only for interfaces of type [ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state).

### `lplpbBuffer` [in]

A pointer to a
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0),
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1),
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2), or [MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3) structure. The *dwLevel* parameter indicates the type of structure.
Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_LEVEL** | The *dwLevel* is 2, but that level is not supported for the interface. For example, the type of interface, as defined in the MPR_INTERFACE_X structure, is not **IF_TYPE_FULL_ROUTER**. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* value is invalid. |

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)

[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2)

[MPR_INTERFACE_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_3)

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)