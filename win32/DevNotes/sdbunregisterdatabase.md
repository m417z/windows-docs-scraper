# SdbUnregisterDatabase function

Unregisters the specified database, making it no longer available.

## Parameters

*pguidDB* \[in\]

The GUID of the database. This parameter cannot be **NULL**.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbRegisterDatabaseEx**](https://learn.microsoft.com/windows/win32/devnotes/sdbregisterdatabaseex)

