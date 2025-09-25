# MprAdminConnectionGetInfo function

## Description

The
**MprAdminConnectionGetInfo** function retrieves data about a specific connection.

## Parameters

### `hRasServer` [in]

A handle to the computer from which the connection information is retrieved. To obtain this handle, call [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, 2, and 3, as listed in the following table.

**Windows NT 4.0:** This parameter must be zero.

| Value | Structure Format |
| --- | --- |
| 0 | [RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0) |
| 1 | Windows 2000 or later: [RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1) |
| 2 | Windows 2000 or later: [RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2) |
| 3 | Windows Server 2008 or later: [RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3) |

### `hRasConnection` [in]

A handle to the connection to retrieve data about. To obtain this handle, call [MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum).

### `lplpbBuffer` [out]

On successful completion, a pointer to an array of structures that describe the connection. These structures are of type [RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0), [RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1), [RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2), or [RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3), depending on the value of the *dwLevel* parameter.

To free this memory, call [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the error codes listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The handle to the RAS server or the handle to the RAS connection is invalid. |
| **ERROR_INVALID_LEVEL** | The value passed for *dwLevel* is not zero, one, two, or three. Levels one and two are supported only on Windows 2000 or later. Level three is supported only on Windows Server 2008 or later. |
| **ERROR_INTERFACE_NOT_CONNECTED** | The *hConnection* handle is invalid. |
| **RPC_S_INVALID_BINDING** | The *hRasServer* handle is invalid. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

This function is available on Windows NT 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll included in the RRAS redistributable exports the function as **RasAdminConnectionGetInfo** rather than
**MprAdminConnectionGetInfo**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)