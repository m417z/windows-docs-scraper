# NDdeIsValidShareName function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Determines whether a share name uses the proper syntax.

## Parameters

*shareName* \[in\]

The share name to be validated. This parameter cannot be **NULL**.

## Return value

If the share name has valid syntax, the return value is nonzero.

If the share name does not have valid syntax, the return value is zero.

## Remarks

This function is also called by [**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd) when it creates the DDE share.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeIsValidShareNameW** (Unicode) and **NDdeIsValidShareNameA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd)

