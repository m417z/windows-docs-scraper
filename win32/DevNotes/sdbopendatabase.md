# SdbOpenDatabase function

Opens the specified shim database.

## Parameters

*pwszPath* \[in\]

The database path. This parameter cannot be **NULL**.

*eType* \[in\]

The path type. See [**PATH\_TYPE**](https://learn.microsoft.com/windows/win32/devnotes/path-type) for a list of values.

## Return value

The function returns a handle to the shim database.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbCreateDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbcreatedatabase)

