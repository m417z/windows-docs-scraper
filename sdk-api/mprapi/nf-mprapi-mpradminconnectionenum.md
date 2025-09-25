# MprAdminConnectionEnum function

## Description

The
**MprAdminConnectionEnum** function enumerates all active connections.

## Parameters

### `hRasServer` [in]

Handle to the RAS server on which connections are enumerated. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Acceptable values for *dwLevel* include 0, 1, 2, and 3, as listed in the following table.

**Windows NT 4.0:** This parameter must be zero.

| Value | Structure Format |
| --- | --- |
| 0 | [RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0) |
| 1 | Windows 2000 or later: [RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1) |
| 2 | Windows 2000 or later: [RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2) |
| 3 | Windows Server 2008 or later: [RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3) |

### `lplpbBuffer` [out]

On successful completion, a pointer to an array of structures that describe the connection. These structures are of type [RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0), [RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1), [RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2), or [RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3), depending on the value of the *dwLevel* parameter.

To free this memory, call [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

### `dwPrefMaxLen` [in]

Specifies the preferred maximum length of returned data in 8-bit bytes. If *dwPrefMaxLen* is -1, the buffer returned is large enough to hold all available information.

### `lpdwEntriesRead` [out]

Pointer to a **DWORD** variable. This variable receives the total number of connections enumerated from the current resume position.

### `lpdwTotalEntries` [out]

Pointer to a **DWORD** variable. This variable receives the total number of connections that could have been enumerated from the current resume position.

### `lpdwResumeHandle` [in]

Pointer to a **DWORD** variable. This variable specifies a resume handle used to continue the enumeration. The *lpdwResumeHandle* parameter is zero on the first call, and left unchanged on subsequent calls. If the return code is ERROR_MORE_DATA, another call may be made using this handle to retrieve more data. If the handle is **NULL** upon return, the enumeration is complete. This handle is invalid for other types of error returns.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **ERROR_INVALID_LEVEL** | The value passed for *dwLevel* is not zero, one, two, or three. Levels one and two are supported only on Windows 2000 or later. Level three is supported only on Windows Server 2008 or later. |
| **ERROR_INVALID_PARAMETER** | At least one of the following parameters is **NULL** or does not point to valid memory: *lplpBuffer*, *lpdwEntriesRead*, or *lpdwTotalEntries*. |
| **ERROR_MORE_DATA** | Not all of the data was returned with this call. To obtain additional data, call the function again using the resume handle. |
| **RPC_S_INVALID_BINDING** | The handle passed in the *hRasServer* parameter is **NULL** or invalid. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

This function is available on Windows NT 4.0 if the RRAS redistributable is installed. However, the version of Mprapi.dll that ships with the RRAS redistributable exports the function as **RasAdminConnectionEnum** rather than
**MprAdminConnectionEnum**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_1)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)