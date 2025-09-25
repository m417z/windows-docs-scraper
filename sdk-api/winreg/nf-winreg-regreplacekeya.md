# RegReplaceKeyA function

## Description

Replaces the file backing a registry key and all its subkeys with another file, so that when the system is next started, the key and subkeys will have the values stored in the new file.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**
**HKEY_CURRENT_CONFIG**
**HKEY_CURRENT_USER**
**HKEY_LOCAL_MACHINE**
**HKEY_USERS**

### `lpSubKey` [in, optional]

The name of the registry key whose subkeys and values are to be replaced. If the key exists, it must be a subkey of the key identified by the *hKey* parameter. If the subkey does not exist, it is created. This parameter can be **NULL**.

If the specified subkey is not the root of a hive,
**RegReplaceKey** traverses up the hive tree structure until it encounters a hive root, then it replaces the contents of that hive with the contents of the data file specified by *lpNewFile*.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `lpNewFile` [in]

The name of the file with the registry information. This file is typically created by using the
[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function.

### `lpOldFile` [in]

The name of the file that receives a backup copy of the registry information being replaced.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

There are two different registry hive file formats. Registry hives created on current operating systems typically cannot be loaded by earlier ones.

The file specified by the *lpNewFile* parameter remains open until the system is restarted.

If *hKey* is a handle returned by
[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya), then the paths specified in *lpNewFile* and *lpOldFile* are relative to the remote computer.

The calling process must have the SE_RESTORE_NAME and SE_BACKUP_NAME privileges on the computer in which the registry resides. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

> [!NOTE]
> The winreg.h header defines RegReplaceKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya)

[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya)

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)