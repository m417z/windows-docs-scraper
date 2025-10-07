# MergeBlob function

The **MergeBlob** function copies all of the entries from the source BLOB into a destination BLOB.

## Parameters

*hDstBlob* \[in, out\]

Handle to the destination BLOB. On input, this BLOB contains its original information. On output, this BLOB contains its original information plus all the information of the source BLOB.

*hSrcBlob* \[in\]

Handle to the source BLOB.

## Return value

If the function is successful, the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value is a NMERR value that indicates the error.

## Remarks

Entries common to source and destination files will be overwritten with data from the source BLOB.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Npptools.lib |
| DLL<br> | Npptools.dll |

