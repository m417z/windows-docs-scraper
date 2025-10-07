# ORDeleteValue function

Removes a named value from the specified registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*lpValueName* \[in, optional\]

The registry value to be removed. If this parameter is **NULL** or an empty string, the default unnamed value set by the [**ORSetValue**](https://learn.microsoft.com/windows/win32/devnotes/orsetvalue) function is removed.

Value names are not case sensitive.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORSetValue**](https://learn.microsoft.com/windows/win32/devnotes/orsetvalue)

