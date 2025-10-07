# SdbRegisterDatabaseEx function

Registers the specified database.

## Parameters

*pszDatabasePath* \[in\]

The database path. This parameter cannot be **NULL**.

*dwDatabaseType* \[in\]

The database type. See [Shim Database Types](https://learn.microsoft.com/windows/win32/devnotes/shim-database-types) for a list of values.

*pTimeStamp* \[in, optional\]

The time stamp for the database. If this parameter is **NULL**, the system time is used.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

A database must be registered before you can use any other SDB functions.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbUnregisterDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbunregisterdatabase)

