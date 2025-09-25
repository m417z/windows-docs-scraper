# MprConfigInterfaceGetHandle function

## Description

The
**MprConfigInterfaceGetHandle** function retrieves a handle to the specified interface's configuration in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `lpwsInterfaceName` [in]

Pointer to a **null**-terminated Unicode string that specifies the name of the interface for which the configuration handle is requested. Use the interface GUID as the name of a LAN interface.

### `phRouterInterface` [out]

Pointer to a handle variable. This variable receives a handle to the interface configuration.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hMprConfig* parameter is **NULL**, or the *lpwsInterfaceName* parameter is **NULL**, or both parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NO_SUCH_INTERFACE** | The specified interface was not found in the router configuration. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)