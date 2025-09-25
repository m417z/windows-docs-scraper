# MprConfigInterfaceCreate function

## Description

The
**MprConfigInterfaceCreate** function creates a router interface in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

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

### `phRouterInterface` [out]

Pointer to a handle variable. This variable receives a handle to the interface configuration.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* *hMprConfig* is **NULL**<br>* *dwLevel* is not 0, 1, 2, or 3.<br>* *lpbBuffer* is **NULL**<br>* *phRouterInterface* is **NULL** |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate) function supports the
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) structure. However,
**MprConfigInterfaceCreate** does not. In order to create a demand-dial interface that is persistent after a reboot, call
**MprAdminInterfaceCreate** with
**MPR_INTERFACE_2**, then call
**MprConfigInterfaceCreate** with
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) or
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigInterfaceDelete](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacedelete)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)