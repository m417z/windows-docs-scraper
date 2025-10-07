# ORSetValue function

Sets the data for the value of a specified registry key in an offline registry hive.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*lpValueName* \[in, optional\]

The name of the value to be set. If a value with this name is not already present in the key, the function adds it to the key.

If *lpValueName* is **NULL** or an empty string, "", the function sets the type and data for the key's unnamed or default value.

For more information, see [Registry Element Size Limits](https://learn.microsoft.com/windows/win32/sysinfo/registry-element-size-limits).

Registry keys do not have default values, but they can have one unnamed value, which can be of any type.

*dwType* \[in\]

The type of data pointed to by the *lpData* parameter. For a list of the possible types, see [Registry Value Types](https://learn.microsoft.com/windows/win32/sysinfo/registry-value-types).

*lpData* \[in, optional\]

The data to be stored.

For string-based types, such as REG\_SZ, the string must be null-terminated. For the REG\_MULTI\_SZ data type, the string must be terminated with two null characters.

*cbData* \[in\]

The size of the information pointed to by the *lpData* parameter, in bytes. If the data is of type REG\_SZ, REG\_EXPAND\_SZ, or REG\_MULTI\_SZ, *cbData* must include the size of the terminating null character or characters.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

## Remarks

Value sizes are limited by available memory. Long values (more than 2048 bytes) should be stored as files with the file names stored in the registry. This helps the registry perform efficiently. Application elements such as icons, bitmaps, and executable files should be stored as files and not be placed in the registry.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**OROpenKey**](https://learn.microsoft.com/windows/win32/devnotes/oropenkey)

