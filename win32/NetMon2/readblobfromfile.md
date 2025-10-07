# ReadBlobFromFile function

The **ReadBlobFromFile** function reads a BLOB in a file.

## Parameters

*hBlob* \[in\]

Handle to the BLOB.

*pFileName* \[in\]

Pointer to the name of the file that contains the BLOB.

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

