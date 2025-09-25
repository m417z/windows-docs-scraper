# MprConfigInterfaceDelete function

## Description

The
**MprConfigInterfaceDelete** function removes a router interface from the router configuration. All transport information associated with this interface is also removed.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate),
[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle), or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hMprConfig* parameter is **NULL**, or the *hRouterInterface* parameter is **NULL**, or both parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)