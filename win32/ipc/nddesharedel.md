# NDdeShareDel function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Deletes a DDE share from the DDE share database manager (DSDM).

## Parameters

*lpszServer* \[in\]

The name of the server whose DSDM is to be modified.

*lpszShareName* \[in\]

The name of the share to be deleted from the DSDM. This parameter cannot be **NULL**.

*wReserved* \[in\]

Reserved. This parameter must be zero.

## Return value

If the function succeeds, the return value is NDDE\_NO\_ERROR.

If the function fails, the return value is an error code which can be translated into a text error message by calling [**NDdeGetErrorString**](https://learn.microsoft.com/windows/win32/ipc/nddegeterrorstring).

## Remarks

To delete a DDE share from the DSDM, you must have the appropriate privilege. The share creator has delete privilege.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeShareDelW** (Unicode) and **NDdeShareDelA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

