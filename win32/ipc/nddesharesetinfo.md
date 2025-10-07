# NDdeShareSetInfo function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Sets DDE share information. This is usually done after editing.

## Parameters

*lpszServer* \[in\]

The name of the server whose DSDM is to be modified.

*lpszShareName* \[in\]

The name of the share name whose information is to be modified. This parameter cannot be **NULL**.

*nLevel* \[in\]

The information level. This parameter must be 2.

*lpBuffer* \[in\]

A pointer to the [**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str) structure that specifies the DDE share information to be stored in the DSDM. Currently the DDE share information is modified as a whole, that is, no partial edits are made. This parameter cannot be **NULL**.

*cBufSize* \[in\]

The size of the *lpBuffer* buffer, in bytes.

*sParmNum* \[in\]

The parameter index to be modified. The current implementation does not support partial modification; therefore, this parameter must be zero.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeShareSetInfoW** (Unicode) and **NDdeShareSetInfoA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str)

[**NDdeShareGetInfo**](https://learn.microsoft.com/windows/win32/ipc/nddesharegetinfo)

