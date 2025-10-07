# RegCreateBlobKey function

The **RegCreateBlobKey** function stores a BLOB at the given registry key.

## Parameters

*hkey* \[out\]

Handle to the registry key where the BLOB will be stored.

*szBlobName* \[in\]

Name (application defined) that represents the BLOB in the registry.

*hBlob* \[in\]

Handle to the BLOB that is saved.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[RegOpenBlobKey](https://learn.microsoft.com/windows/win32/netmon2/regopenblobkey)

