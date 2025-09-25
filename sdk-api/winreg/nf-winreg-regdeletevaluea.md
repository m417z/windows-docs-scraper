# RegDeleteValueA function

## Description

Removes a named value from the specified registry key. Note that value names are not case sensitive.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_SET_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

```
   HKEY_CLASSES_ROOT
   HKEY_CURRENT_CONFIG
   HKEY_CURRENT_USER
   HKEY_LOCAL_MACHINE
   HKEY_USERS
```

### `lpValueName` [in, optional]

The registry value to be removed. If this parameter is **NULL** or an empty string, the value set by the
[RegSetValueEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsetvalueexa) function is removed.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## See also

[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)

## Remarks

> [!NOTE]
> The winreg.h header defines RegDeleteValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).