# SdbCloseDatabaseWrite function

Closes the specified database.

## Parameters

*pdb* \[in, out\]

A handle to the shim database.

## Return value

This function does not return a value.

## Remarks

This function calls [**SdbCloseDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabase); therefore, these two functions are equivalent.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbBeginWriteListTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbbeginwritelisttag)

[**SdbCloseDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbclosedatabase)

[**SdbEndWriteListTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbendwritelisttag)

