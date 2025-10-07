# NDdeShareGetInfo function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Retrieves DDE share information. This is usually done for editing.

## Parameters

*lpszServer* \[in\]

The name of the server on which the DSDM resides.

*lpszShareName* \[in\]

The share name whose information is to be retrieved from the DSDM. This parameter must not be **NULL**.

*nLevel* \[in\]

The information level. This parameter must be 2.

*lpBuffer* \[out\]

A pointer to a buffer that receives the [**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str) structure and associated data pointed to by its members. This parameter can be **NULL**. If *lpBuffer* is **NULL**, then the DSDM calculates the number of bytes required to store the requested share information and returns that value in the *lpnTotalAvailable* field along with the NDDE\_BUF\_TOO\_SMALL error.

*cBufSize* \[in\]

The size of the *lpBuffer* buffer, in bytes. If *lpBuffer* is **NULL**, then *cBufSize* should be zero.

*lpnTotalAvailable* \[out\]

A pointer to a variable that receives the total number of bytes needed to store the requested share information. This parameter cannot be **NULL**.

*lpnItems* \[in\]

A pointer to an item selection mask for partial share information retrieval.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring). If the *lpBuffer* parameter is **NULL**, it returns NDDE\_BUF\_TOO\_SMALL.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeShareGetInfoW** (Unicode) and **NDdeShareGetInfoA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str)

[**NDdeShareSetInfo**](https://learn.microsoft.com/windows/win32/ipc/nddesharesetinfo)

