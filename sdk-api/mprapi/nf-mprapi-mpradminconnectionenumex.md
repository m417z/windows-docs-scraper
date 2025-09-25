# MprAdminConnectionEnumEx function

## Description

The
**MprAdminConnectionEnumEx** function enumerates the active connections for a specified RRAS server.

## Parameters

### `hRasServer` [in]

A handle to the RAS server on which connections are enumerated. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `pObjectHeader` [in]

A pointer to an [MPRAPI_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_object_header) structure that specifies the structure version received by *ppRasConn*.

### `dwPreferedMaxLen` [in]

A value that specifies the preferred maximum length of returned data in 8-bit bytes. If *dwPrefMaxLen* is -1, the buffer returned is large enough to hold all available information.

### `lpdwEntriesRead` [out]

A pointer to a **DWORD** that receives the total number of connections enumerated from the current resume position.

### `lpdwTotalEntries` [out]

A pointer to a **DWORD** that receives the total number of connections that could have been enumerated from the current resume position.

### `ppRasConn` [out]

A pointer, on output, to an array of [RAS_CONNECTION_EX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_ex) structures that contain the active connection information for the RRAS server in *hRasServer*. The number of array elements is determined by the value pointed to by *lpdwEntriesRead*.

### `lpdwResumeHandle` [in]

A pointer to a **DWORD** variable that specifies a resume handle used to continue the enumeration. The *lpdwResumeHandle* parameter is **NULL** on the first call, and left unchanged on subsequent calls. If the return code is **ERROR_MORE_DATA**, another call may be made using this handle to retrieve more data. If the handle is **NULL** upon return, the enumeration is complete. This handle is invalid for other types of error returns.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_MORE_DATA** | Not all of the data was returned with this call. To obtain additional data, call the function again using the resume handle. |
| **ERROR_PROC_NOT_FOUND** | The specified procedure could not be found. |
| **Other** | An error from MprError.h, RasError.h, or WinError.h. |

## Remarks

The caller should free the memory pointed to by *ppRasConn* by calling the function [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)