# NDdeGetErrorString function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Converts an error code returned by a network DDE function into an error string that explains the returned error code.

## Parameters

*uErrorCode* \[in\]

The error code to be converted into an error string.

*lpszErrorString* \[out\]

A pointer to a buffer that receives the translated error string. This parameter cannot be **NULL**. If the buffer is not large enough to store the complete error string, the string is truncated.

*cBufSize* \[in\]

The size of the buffer to receive the error string, in **TCHARs**.

## Return value

If the function succeeds, the return value is zero.

If the function fails, the return value is a nonzero error code. If the *lpszErrorString* buffer is not large enough to accept the complete error string, and the string is truncated, the function returns the value NDDE\_INTERNAL\_ERROR.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeGetErrorStringW** (Unicode) and **NDdeGetErrorStringA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

