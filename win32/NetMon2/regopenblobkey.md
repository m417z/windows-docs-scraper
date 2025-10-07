# RegOpenBlobKey function

The **RegOpenBlobKey** function retrieves a BLOB stored at the given registry key.

## Parameters

*hkey* \[in\]

Handle to the registry key that contains the BLOB.

*szBlobName* \[in\]

Name that identifies the given BLOB in the registry.

*phBlob* \[out\]

Pointer to the BLOB that is retrieved.

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

[RegCreateBlobKey](https://learn.microsoft.com/windows/win32/netmon2/regcreateblobkey)

