# MprAdminInterfaceEnum function

## Description

The
**MprAdminInterfaceEnum** function enumerates all the interfaces on a specified server.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Must be zero.

### `lplpbBuffer` [out]

On successful completion, a pointer to an array of [MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0) structures. Free this memory buffer by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

### `dwPrefMaxLen` [in]

Specifies the preferred maximum length of returned data (in 8-bit bytes). If this parameter is -1, the buffer returned is large enough to hold all available information.

### `lpdwEntriesRead` [out]

Pointer to a **DWORD** variable. This variable receives the total number of interfaces that were enumerated from the current position in the enumeration.

### `lpdwTotalEntries` [out]

Pointer to a **DWORD** variable. This variable receives the total number of interfaces that could have been enumerated from the current resume position.

### `lpdwResumeHandle` [in]

Pointer to a **DWORD** variable. This variable specifies a resume handle that can be used to continue the enumeration. The handle should be zero on the first call, and left unchanged on subsequent calls. If the return code is ERROR_MORE_DATA then the call can be re-issued using the handle to retrieve more data. If on return, the handle is **NULL**, the enumeration cannot be continued. For other types of error returns, this handle is invalid.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return a resume handle.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_MORE_DATA** | More information is available; the enumeration can be continued. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NOT_SUPPORTED** | The value of *dwLevel* is invalid. |

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)