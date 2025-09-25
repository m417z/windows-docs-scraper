# MprConfigInterfaceSetInfo function

## Description

The
**MprConfigInterfaceSetInfo** function sets the configuration for the specified interface.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration being updated. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate),
[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle), or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

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
The information in this structure is used to update the interface configuration.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true:<br><br>* *hMprConfig* is **NULL**.<br>* *hRouterInterface* is **NULL**.<br>* *dwLevel* is not 0, 1, 2, or 3.<br>* *lpBuffer* is **NULL**.<br><br>Also returns this error code if the interface is of type [ROUTER_IF_TYPE_DEDICATED](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type) or **ROUTER_IF_TYPE_INTERNAL** and the interface is enabled. |
| **ERROR_NO_SUCH_INTERFACE** | The interface that corresponds to *hRouterInterface* is not present in the router configuration. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

The
[MprAdminInterfaceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetinfo) function supports the
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) structure. However,
**MprConfigInterfaceSetInfo** does not. In order to make persistent changes to a demand-dial interface, call
**MprAdminInterfaceSetInfo** with
**MPR_INTERFACE_2**, then call
**MprConfigInterfaceSetInfo** with
[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) or
[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)