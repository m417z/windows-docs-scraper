# SdbBeginWriteListTag function

Creates a new list TAG for write operations.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tTag* \[in\]

The TAG for the new entry. This value must be of type **TAG\_TYPE\_LIST**.

## Return value

The function returns the [**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid) of the new list on success or **TAGID\_NULL** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbCloseDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabase)

[**SdbCloseDatabaseWrite**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabasewrite)

[**SdbEndWriteListTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbendwritelisttag)

[**TAG**](https://learn.microsoft.com/windows/win32/devnotes/tag)

[TAG Types](https://learn.microsoft.com/windows/win32/devnotes/tag-types)

[**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid)

