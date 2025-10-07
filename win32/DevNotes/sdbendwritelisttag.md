# SdbEndWriteListTag function

Ends the write operations for the specified list.

## Parameters

*pdb* \[in, out\]

A handle to the shim database.

*tiList* \[in\]

The [**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid) of the list

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

Call this function after writing all list entries; it will mark the end of the list.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbBeginWriteListTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbbeginwritelisttag)

[**SdbCloseDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabase)

[**SdbCloseDatabaseWrite**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabasewrite)

