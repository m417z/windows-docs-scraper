# RegDeleteKeyValueW function

## Description

Removes the specified value from the specified registry key and subkey.

## Parameters

### `hKey` [in]

A handle to an open registry key. The key must have been opened with the KEY_SET_VALUE access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

```
   HKEY_CLASSES_ROOT
   HKEY_CURRENT_CONFIG
   HKEY_CURRENT_USER
   HKEY_LOCAL_MACHINE
   HKEY_USERS
```

### `lpSubKey` [in, optional]

The name of the registry key. This key must be a subkey of the key identified by the *hKey* parameter.

### `lpValueName` [in, optional]

The registry value to be removed from the key.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

> [!NOTE]
> The winreg.h header defines RegDeleteKeyValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegSetKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetkeyvaluea)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)