# ORCloseKey function

Closes a handle to the specified registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the specified key is the root key of the registry hive, the function fails with ERROR\_INVALID\_PARAMETER.

## Remarks

The handle for a specified key should not be used after it has been closed, because it will no longer be valid. Key handles should not be left open any longer than necessary.

Use the [**ORCloseHive**](https://learn.microsoft.com/windows/win32/devnotes/orclosehive) function to close an offline registry hive.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseHive**](https://learn.microsoft.com/windows/win32/devnotes/orclosehive)

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

