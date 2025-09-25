# RegRestoreKeyW function

## Description

Reads the registry information in a specified file and copies it over the specified key. This registry information may be in the form of a key and multiple levels of subkeys.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**
**HKEY_CURRENT_CONFIG**
**HKEY_CURRENT_USER**
**HKEY_LOCAL_MACHINE**
**HKEY_USERS**
Any information contained in this key and its descendent keys is overwritten by the information in the file pointed to by the *lpFile* parameter.

### `lpFile` [in]

The name of the file with the registry information. This file is typically created by using the
[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function.

### `dwFlags` [in]

The flags that indicate how the key or keys are to be restored. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **REG_FORCE_RESTORE**<br><br>0x00000008L | If specified, the restore operation is executed even if open handles exist at or beneath the location in the registry hierarchy to which the *hKey* parameter points. |
| **REG_WHOLE_HIVE_VOLATILE**<br><br>0x00000001L | If specified, a new, volatile (memory only) set of registry information, or hive, is created. If REG_WHOLE_HIVE_VOLATILE is specified, the key identified by the *hKey* parameter must be either the **HKEY_USERS** or **HKEY_LOCAL_MACHINE** value. |

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

There are two different registry hive file formats. Registry hives created on current operating systems typically cannot be loaded by earlier ones.

If any subkeys of the *hKey* parameter are open,
**RegRestoreKey** fails.

The calling process must have the SE_RESTORE_NAME and SE_BACKUP_NAME privileges on the computer in which the registry resides. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

This function replaces the keys and values below the specified key with the keys and values that are subsidiary to the top-level key in the file, no matter what the name of the top-level key in the file might be. For example, *hKey* might identify a key A with subkeys B and C, while the *lpFile* parameter specifies a file containing key X with subkeys Y and Z. After a call to
**RegRestoreKey**, the registry would contain key A with subkeys Y and Z. The value entries of A would be replaced by the value entries of X.

The new information in the file specified by *lpFile* overwrites the contents of the key specified by the *hKey* parameter, except for the key name.

If *hKey* represents a key in a remote computer, the path described by *lpFile* is relative to the remote computer.

> [!NOTE]
> The winreg.h header defines RegRestoreKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya)

[RegReplaceKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regreplacekeya)

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)