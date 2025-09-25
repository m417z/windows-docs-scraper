# RegSetKeyValueW function

## Description

Sets the data for the specified value in the specified registry key and subkey.

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

### `lpSubKey` [in, optional]

The name of the subkey relative to the key identified by *hKey*.
If the subkey does not exist, it is created as a non-volatile key with a default security descriptor.
If this parameter is **NULL**, then the value is created in the key specified by *hKey*.

### `lpValueName` [in, optional]

The name of the registry value whose data is to be updated.

### `dwType` [in]

The type of data pointed to by the *lpData* parameter. For a list of the possible types, see
[Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

### `lpData` [in, optional]

The data to be stored with the specified value name.

For string-based types, such as REG_SZ, the string must be null-terminated. With the REG_MULTI_SZ data type, the string must be terminated with two null characters.

### `cbData` [in]

The size of the information pointed to by the *lpData* parameter, in bytes. If the data is of type REG_SZ, REG_EXPAND_SZ, or REG_MULTI_SZ, *cbData* must include the size of the terminating null character or characters.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winreg.h header defines RegSetKeyValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegDeleteKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeyvaluea)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)