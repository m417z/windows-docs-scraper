# NDdeSetShareSecurity function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Sets the security descriptor associated with the DDE share. This is done usually after editing the DACL assigned to the DDE share.

## Parameters

*lpszServer* \[in\]

The name of the server whose DSDM is to be modified.

*lpszShareName* \[in\]

The name of the share whose security descriptor is to be modified. This parameter cannot be **NULL**.

*si* \[in\]

A [**SECURITY\_INFORMATION**](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that identifies the security information to retrieve.

*pSD* \[in\]

A pointer to a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains security information. This parameter cannot be **NULL** and should point to a valid security descriptor.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code, which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Remarks

To modify the [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) associated with a DDE share in the DSDM, the user must have appropriate privilege; the share creator has this privilege.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeSetShareSecurityW** (Unicode) and **NDdeSetShareSecurityA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**SECURITY\_INFORMATION**](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

[**NDdeGetShareSecurity**](https://learn.microsoft.com/windows/win32/ipc/nddegetsharesecurity)

