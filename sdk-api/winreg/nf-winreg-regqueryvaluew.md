# RegQueryValueW function

## Description

Retrieves the data associated with the default or unnamed value of a specified registry key. The data must be a **null**-terminated string.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_QUERY_VALUE access right. For more information, see
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

The name of the subkey of the *hKey* parameter for which the default value is retrieved.

Key names are not case sensitive.

If this parameter is **NULL** or points to an empty string, the function retrieves the default value for the key identified by *hKey*.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpData` [out, optional]

A pointer to a buffer that receives the default value of the specified key.

If *lpValue* is **NULL**, and *lpcbValue* is non-**NULL**, the function returns ERROR_SUCCESS, and stores the size of the data, in bytes, in the variable pointed to by *lpcbValue*. This enables an application to determine the best way to allocate a buffer for the value's data.

### `lpcbData` [in, out, optional]

A pointer to a variable that specifies the size of the buffer pointed to by the *lpValue* parameter, in bytes. When the function returns, this variable contains the size of the data copied to *lpValue*, including any terminating **null** characters.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, this size includes any terminating **null** character or characters. For more information, see Remarks.

If the buffer specified *lpValue* is not large enough to hold the data, the function returns ERROR_MORE_DATA and stores the required buffer size in the variable pointed to by *lpcbValue*. In this case, the contents of the *lpValue* buffer are undefined.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

If the *lpValue* buffer is too small to receive the value, the function returns ERROR_MORE_DATA.

## Remarks

If the ANSI version of this function is used (either by explicitly calling **RegQueryValueA** or by not defining UNICODE before including the Windows.h file), this function converts the stored Unicode string to an ANSI string before copying it to the buffer specified by the *lpValue* parameter.

If the data has the REG_SZ, REG_MULTI_SZ or REG_EXPAND_SZ type, the string may not have been stored with the proper **null**-terminating characters. Therefore, even if the function returns ERROR_SUCCESS, the application should ensure that the string is properly terminated before using it; otherwise, it may overwrite a buffer. (Note that REG_MULTI_SZ strings should have two **null**-terminating characters.)

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

> [!NOTE]
> The winreg.h header defines RegQueryValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)

[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)