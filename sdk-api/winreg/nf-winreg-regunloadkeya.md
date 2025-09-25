# RegUnLoadKeyA function

## Description

Unloads the specified registry key and its subkeys from the registry.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to the registry key to be unloaded. This parameter can be a handle returned by a call to
[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya) function or one of the following predefined handles:

**HKEY_LOCAL_MACHINE**
**HKEY_USERS**

### `lpSubKey` [in, optional]

The name of the subkey to be unloaded. The key referred to by the *lpSubKey* parameter must have been created by using the
[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya) function.

Key names are not case sensitive.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

This function removes a hive from the registry but does not modify the file containing the registry information. A hive is a discrete body of keys, subkeys, and values that is rooted at the top of the registry hierarchy.

The calling process must have the SE_RESTORE_NAME and SE_BACKUP_NAME privileges on the computer in which the registry resides. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

> [!NOTE]
> The winreg.h header defines RegUnLoadKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya)

[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)