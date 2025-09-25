# RegCopyTreeW function

## Description

Copies the specified registry key, along with its values and subkeys, to the specified destination key.

## Parameters

### `hKeySrc` [in]

A handle to an open registry key. The key must have been opened with the KEY_READ access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the [predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys).

### `lpSubKey` [in, optional]

The name of the key. This key must be a subkey of the key identified by the *hKeySrc* parameter. This parameter can also be **NULL**.

### `hKeyDest` [in]

A handle to the destination key. The calling process must have KEY_CREATE_SUB_KEY access to the key.

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the [predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

This function also copies the security descriptor for the key.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winreg.h header defines RegCopyTree as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)