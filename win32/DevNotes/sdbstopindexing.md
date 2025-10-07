# SdbStopIndexing function

Disables index creation and modification for the specified database.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*iiWhich* \[in\]

The index identifier.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbCommitIndexes**](https://learn.microsoft.com/windows/win32/devnotes/sdbcommitindexes)

[**SdbDeclareIndex**](https://learn.microsoft.com/windows/win32/devnotes/sdbdeclareindex)

[**SdbStartIndexing**](https://learn.microsoft.com/windows/win32/devnotes/sdbstartindexing)

