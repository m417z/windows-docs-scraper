# MprAdminDeviceEnum function

## Description

The **MprAdminDeviceEnum** function is called to enumerate RAS capable devices installed on the computer that can return their name and type.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwLevel` [in]

A DWORD value that describes the format in which the information is returned in the *lplpbBuffer* parameter. Must be zero.

### `lplpbBuffer` [out]

On successful completion, an array of [MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0) structures that contains the RAS capable device information. Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

### `lpdwTotalEntries` [out]

The number of entries of type [MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0) in *lplpbBuffer*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_SUPPORTED** | The *dwlevel* parameter does not equal zero. |
| **ERROR_INVALID_PARAMETER** | The *lplpbBuffer* or *lpdwTotalEntries* parameter is **NULL**. |

## See also

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)