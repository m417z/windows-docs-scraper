# RegSetValueW function

## Description

Sets the data for the default or unnamed value of a specified registry key. The data must be a text string.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) function.

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

### `lpSubKey` [in, optional]

The name of a subkey of the *hKey* parameter. The function sets the default value of the specified subkey. If *lpSubKey* does not exist, the function creates it.

Key names are not case sensitive.

If this parameter is **NULL** or points to an empty string, the function sets the default value of the key identified by *hKey*.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `dwType` [in]

The type of information to be stored. This parameter must be the REG_SZ type. To store other data types, use the
[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) function.

### `lpData` [in]

The data to be stored. This parameter cannot be **NULL**.

### `cbData` [in]

This parameter is ignored. The function calculates this value based on the size of the data in the *lpData* parameter.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

If the key specified by the *lpSubKey* parameter does not exist, the
**RegSetValue** function creates it.

If the ANSI version of this function is used (either by explicitly calling **RegSetValueA** or by not defining UNICODE before including the Windows.h file), the *lpData* parameter must be an ANSI character string. The string is converted to Unicode before it is stored in the registry.

> [!NOTE]
> The winreg.h header defines RegSetValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegFlushKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regflushkey)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)

[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)