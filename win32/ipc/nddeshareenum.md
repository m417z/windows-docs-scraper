# NDdeShareEnum function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Retrieves the list of available DDE shares.

## Parameters

*lpszServer* \[in\]

The name of the server on which the DSDM resides.

*nLevel* \[in\]

Reserved. This parameter must be zero.

*lpBuffer* \[out\]

A pointer to a buffer that receives the list of DDE shares. The list of DDE shares is stored as a sequence of null-separated strings terminating with a double null character at the end. This parameter can be **NULL**. If *lpBuffer* is **NULL**, the DSDM returns the size of buffer required to hold the list of shares in the *lpcbTotalAvailable* parameter.

*cBufSize* \[in\]

The size of the *lpBuffer* buffer, in bytes. This parameter must be zero if *lpBuffer* is **NULL**.

*lpnEntriesRead* \[out\]

A pointer to a variable that receives the total number of shares being enumerated. This parameter cannot be **NULL**.

*lpcbTotalAvailable* \[out\]

A pointer to a variable that receives the total number of bytes needed in the buffer to store the list of DDE shares. This parameter cannot be **NULL**.

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
| Unicode and ANSI names<br> | **NDdeShareEnumW** (Unicode) and **NDdeShareEnumA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

