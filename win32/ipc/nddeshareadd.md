# NDdeShareAdd function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Creates and adds a new DDE share to the DDE share database manager (DSDM).

## Parameters

*lpszServer* \[in\]

The name of the server whose DSDM is to be modified.

*nLevel* \[in\]

The information level. This parameter must be 2.

*pSD* \[in\]

A pointer to a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to be associated with this share and against which access checks will be performed on subsequent initiates to this share. This parameter can be **NULL**, in which case the DSDM creates a default security descriptor that grants "Full Control" to the owner and "Read and Link" to everyone.

*lpBuffer* \[in\]

A pointer to the [**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str) structure that defines the ApplicationTopic list associated with the DDE share being created as well as other parameters. This parameter cannot be **NULL**.

*cBufSize* \[in\]

The size of the *lpBuffer* structure, in bytes. This parameter cannot be zero.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Remarks

Before a client can connect to the DDE share, it must be trusted with [**NDdeSetTrustedShare**](https://learn.microsoft.com/windows/win32/ipc/nddesettrustedshare).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeShareAddW** (Unicode) and **NDdeShareAddA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDDESHAREINFO**](https://learn.microsoft.com/windows/win32/ipc/nddeshareinfo-str)

[**NDdeSetTrustedShare**](https://learn.microsoft.com/windows/win32/ipc/nddesettrustedshare)

