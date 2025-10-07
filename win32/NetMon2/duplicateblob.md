# DuplicateBlob function

The **DuplicateBlob** function copies a specific BLOB.

## Parameters

*hSrcBlob* \[in\]

Handle to the BLOB that is copied.

*hBlobThatWillBeCreated* \[out\]

Handle to the duplicate BLOB.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that describes the error.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

## See also

[CreateBlob](https://learn.microsoft.com/windows/win32/netmon2/createblob)

[DestroyBlob](https://learn.microsoft.com/windows/win32/netmon2/destroyblob)

