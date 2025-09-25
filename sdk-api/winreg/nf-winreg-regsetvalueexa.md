# RegSetValueExA function

## Description

Sets the data and type of a specified value under a registry key.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_SET_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

The Unicode version of this function supports the following additional predefined keys:

* **HKEY_PERFORMANCE_TEXT**
* **HKEY_PERFORMANCE_NLSTEXT**

### `lpValueName` [in, optional]

The name of the value to be set. If a value with this name is not already present in the key, the function adds it to the key.

If *lpValueName* is **NULL** or an empty string, "", the function sets the type and data for the key's unnamed or default value.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

Registry keys do not have default values, but they can have one unnamed value, which can be of any type.

### `Reserved`

This parameter is reserved and must be zero.

### `dwType` [in]

The type of data pointed to by the *lpData* parameter. For a list of the possible types, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

### `lpData` [in]

The data to be stored.

For string-based types, such as REG_SZ, the string must be **null**-terminated. With the REG_MULTI_SZ data type, the string must be terminated with two **null** characters.

**Note** lpData indicating a **null** value is valid, however, if this is the case, *cbData* must be set to '0'.

### `cbData` [in]

The size of the information pointed to by the *lpData* parameter, in bytes. If the data is of type REG_SZ, REG_EXPAND_SZ, or REG_MULTI_SZ, *cbData* must include the size of the terminating **null** character or characters.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

Value sizes are limited by available memory. However, storing large values in the registry can affect its performance. Long values (more than 2,048 bytes) should be stored as files, with the locations of the files stored in the registry.

Application elements such as icons, bitmaps, and executable files should be stored as files and not be placed in the registry.

If *dwType* is the REG_SZ, REG_MULTI_SZ, or REG_EXPAND_SZ type and the ANSI version of this function is used (either by explicitly calling **RegSetValueExA** or by not defining UNICODE before including the Windows.h file), the data pointed to by the *lpData* parameter must be an ANSI character string. The string is converted to Unicode before it is stored in the registry.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

Consider using the [RegSetKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeyvaluea) function, which provides a more convenient way to set the value of a registry key.

> [!NOTE]
> The winreg.h header defines RegSetValueEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegSetKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeyvaluea)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegFlushKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regflushkey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)