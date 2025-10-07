# OROpenKey function

Opens the specified registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*lpSubKeyName* \[in, optional\]

A pointer to a UNICODE string that contains the name of the registry key to be opened. This key must be a subkey of the key identified by the *Handle* parameter.

Key names are not case sensitive.

If this parameter is **NULL** or a pointer to an empty string, the function returns the same handle that was passed in. If the key specified by the *Handle* parameter is the root key of the hive, the function returns ERROR\_INVALID\_PARAMETER.

For more information, see [Registry Element Size Limits](https://learn.microsoft.com/windows/win32/sysinfo/registry-element-size-limits).

*phkResult* \[out\]

A pointer to a variable that receives a handle to the opened key. Use the [**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey) function to close the key after you have finished using the handle.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the handle to be returned would be a handle to the root key of the hive, the function returns ERROR\_INVALID\_PARAMETER.

If the specified key has been marked as deleted, this function returns ERROR\_KEY\_DELETED.

## Remarks

The **OROpenKey** function cannot be used to open the root key in an offline registry hive. To obtain a handle to the root key of a hive, use the [**OROpenHive**](https://learn.microsoft.com/windows/win32/devnotes/oropenhive) function to load the hive into memory.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey)

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**OROpenHive**](https://learn.microsoft.com/windows/win32/devnotes/oropenhive)

