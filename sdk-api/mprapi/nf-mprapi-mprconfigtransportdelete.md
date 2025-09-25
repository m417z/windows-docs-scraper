# MprConfigTransportDelete function

## Description

The
**MprConfigTransportDelete** function removes the specified transport from the list of transports present in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration from which to remove the transport. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterTransport` [in]

Handle to the configuration for the transport being deleted. Obtain this handle by calling
[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate) or
[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hMprConfig* parameter is **NULL**, or the *hRouterTransport* parameter is **NULL**, or both are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate)

[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)