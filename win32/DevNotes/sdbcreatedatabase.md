# SdbCreateDatabase function

Creates a new shim database.

## Parameters

*pwszPath* \[in\]

The path where the database should be saved. This parameter cannot be **NULL**.

*eType* \[in\]

The path type. See [**PATH\_TYPE**](https://learn.microsoft.com/windows/win32/devnotes/path-type) for a list of values.

## Return value

The function returns a handle to the shim database or **NULL** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbOpenDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbopendatabase)

