# MprAdminPortEnum function

## Description

The
**MprAdminPortEnum** function enumerates all active ports in a specific connection, or all ports available for use or currently used by RAS.

## Parameters

### `hRasServer` [in]

A handle to the RAS server whose ports are to be enumerated. To obtain this handle, call [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Must be zero.

### `hRasConnection` [in]

A handle to a connection for which the active ports are enumerated. If this parameter is **INVALID_HANDLE_VALUE**, all the ports in use or available for use by RRAS are enumerated. To obtain this handle, call
[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum).

### `lplpbBuffer` [out]

On successful completion, a pointer to an array of [RAS_PORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_port_0) structures that describes the port. Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

### `dwPrefMaxLen` [in]

A value that specifies the preferred maximum length of returned data, in 8-bit bytes. If this parameter is -1, the buffer that is returned is large enough to hold all available data.

### `lpdwEntriesRead` [out]

A pointer to a **DWORD** variable. This variable receives the total number of ports that are enumerated from the current resume position.

### `lpdwTotalEntries` [out]

A pointer to a **DWORD** variable. This variable receives the total number of ports that could have been enumerated from the current resume position.

### `lpdwResumeHandle` [in]

A pointer to a **DWORD** variable. On successful execution, this parameter specifies a handle that can be used to resume the enumeration. This parameter should be zero on the first call and left unchanged on subsequent calls. If the return code is **ERROR_MORE_DATA**, the call can be reissued with the handle to retrieve more data. If the handle is **NULL** on return, the enumeration cannot be continued. This handle is invalid for other types of error returns.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the error codes listed in the following table.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running, possibly because the Dynamic Interface Manager (DIM) is configured to run only on a LAN. |
| **ERROR_INVALID_PARAMETER** | At least one of the following parameters is **NULL** or does not point to valid memory: *lplpBuffer*, *lpdwEntriesRead*, or *lpdwTotalEntries*. |
| **ERROR_MORE_DATA** | Not all of the data was returned with this call. To obtain additional data, call the function again using the handle that was returned in the *IpdwResumeHandle* parameter. |
| **ERROR_NOT_SUPPORTED** | The *dwLevel* parameter is not zero. |
| **ERROR_INVALID_HANDLE** | The *hConnection* parameter is **NULL**. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

If the RRAS redistributable is installed, this function is available on Windows NT 4.0. However, the version of Mprapi.dll that is provided with the RRAS redistributable exports the function as
**RasAdminPortEnum** rather than
**MprAdminPortEnum**. Therefore, when using the RRAS redistributable, use
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access this function.

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)