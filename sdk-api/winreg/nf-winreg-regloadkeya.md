# RegLoadKeyA function

## Description

Creates a subkey under **HKEY_USERS** or **HKEY_LOCAL_MACHINE** and loads the data from the specified registry hive into that subkey.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to the key where the subkey will be created. This can be a handle returned by a call to
[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya), or one of the following predefined handles:

**HKEY_LOCAL_MACHINE**
**HKEY_USERS**
This function always loads information at the top of the registry hierarchy. The **HKEY_CLASSES_ROOT** and **HKEY_CURRENT_USER** handle values cannot be specified for this parameter, because they represent subsets of the **HKEY_LOCAL_MACHINE** and **HKEY_USERS** handle values, respectively.

### `lpSubKey` [in, optional]

The name of the key to be created under *hKey*. This subkey is where the registration information from the file will be loaded.

Key names are not case sensitive.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpFile` [in]

The name of the file containing the registry data. This file must be a local file that was created with the
[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function. If this file does not exist, a file is created with the specified name.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

There are two registry hive file formats. Registry hives created on current operating systems typically cannot be loaded by earlier ones.

If *hKey* is a handle returned by
[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya), then the path specified in *lpFile* is relative to the remote computer.

The calling process must have the SE_RESTORE_NAME and SE_BACKUP_NAME privileges on the computer in which the registry resides. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges). To load a hive without requiring these special privileges, use the [RegLoadAppKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadappkeya) function.

> [!NOTE]
> The winreg.h header defines RegLoadKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegLoadAppKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadappkeya)

[RegReplaceKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regreplacekeya)

[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya)

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[RegUnLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regunloadkeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Hive](https://learn.microsoft.com/windows/desktop/SysInfo/registry-hives)