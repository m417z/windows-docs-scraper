# NDdeGetShareSecurity function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Retrieves the security descriptor associated with the DDE share. This is done usually for editing.

## Parameters

*lpszServer* \[in\]

The name of the server on which the DSDM resides.

*lpszShareName* \[in\]

The name of the share whose security descriptor is to be retrieved from the DSDM. This parameter cannot be **NULL**.

*si* \[in\]

A [**SECURITY\_INFORMATION**](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies the security information to be retrieved from the security descriptor associated with the share.

*pSD* \[out\]

A pointer to a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that receives the self-relative security descriptor. This parameter can be **NULL**. If this parameter is **NULL**, the DSDM determines the size of the requested security information and returns the number of bytes needed in the *lpcbsdRequired* parameter along with the NDDE\_BUF\_TOO\_SMALL error code.

*cbSD* \[in\]

The size of the *pSD* buffer. This parameter must be zero if *pSD* is **NULL**.

*lpcbsdRequired* \[out\]

A pointer to the variable that receives the actual size of the retrieved security descriptor. This parameter cannot be **NULL**.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring). If the *pSD* parameter was **NULL**, it returns NDDE\_BUF\_TOO\_SMALL.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeGetShareSecurityW** (Unicode) and **NDdeGetShareSecurityA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**SECURITY\_INFORMATION**](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[**NDdeSetShareSecurity**](https://learn.microsoft.com/windows/win32/ipc/nddesetsharesecurity)

