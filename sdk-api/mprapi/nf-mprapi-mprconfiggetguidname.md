# MprConfigGetGuidName function

## Description

The
**MprConfigGetGuidName** function returns the GUID name for an interface that corresponds to the specified friendly name.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `pszFriendlyName` [in]

Pointer to a Unicode string that specifies the friendly name for the interface.

### `pszBuffer` [out]

Pointer to a buffer that receives the GUID name for the interface.

### `dwBufferSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pszBuffer*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The buffer pointed to by *pszBuffer* is not large enough to hold the returned GUID name. |
| **ERROR_INVALID_PARAMETER** | At least one of the parameters *hMprConfig*, *pszFriendlyName*, or *pszBuffer* is **NULL**. |
| **ERROR_NOT_FOUND** | No GUID name was found that corresponds to the specified friendly name. |

## See also

[MprConfigGetFriendlyName](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiggetfriendlyname)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)