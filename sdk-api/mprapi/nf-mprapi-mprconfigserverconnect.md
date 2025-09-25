# MprConfigServerConnect function

## Description

The
**MprConfigServerConnect** function connects to the router to be configured. Call this function before making any other calls to the server. The handle returned by this function is used in subsequent calls to configure interfaces and transports on the server.

## Parameters

### `lpwsServerName` [in]

Pointer to a Unicode string that specifies the name of the remote server to configure. If this parameter is **NULL**, the function returns a handle to the router configuration on the local machine.

### `phMprConfig` [out]

Pointer to a handle variable. This variable receives a handle to the router configuration.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *phMprConfig* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigServerDisconnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverdisconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)