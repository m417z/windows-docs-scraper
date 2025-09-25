# RegSaveKeyA function

## Description

Saves the specified key and all of its subkeys and values to a new file, in the standard format.

To specify the format for the saved key or hive, use the [RegSaveKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeyexa) function.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key.

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_USER**

### `lpFile` [in]

The name of the file in which the specified key and subkeys are to be saved. If the file already exists, the function fails.

If the string does not include a path, the file is created in the current directory of the calling process for a local key, or in the %systemroot%\system32 directory for a remote key. The new file has the archive attribute.

### `lpSecurityAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new file. If *lpSecurityAttributes* is **NULL**, the file gets a default security descriptor. The ACLs in a default security descriptor for a file are inherited from its parent directory.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

If the file already exists, the function fails with the ERROR_ALREADY_EXISTS error.

## Remarks

If *hKey* represents a key on a remote computer, the path described by *lpFile* is relative to the remote computer.

The
**RegSaveKey** function saves only nonvolatile keys. It does not save volatile keys. A key is made volatile or nonvolatile at its creation; see
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa).

You can use the file created by
**RegSaveKey** in subsequent calls to the
[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya),
[RegReplaceKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regreplacekeya), or
[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya) functions. If
**RegSaveKey** fails part way through its operation, the file will be corrupt and subsequent calls to
**RegLoadKey**,
**RegReplaceKey**, or
**RegRestoreKey** for the file will fail.

Using **RegSaveKey** together with
[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya) to copy subtrees in the registry is not recommended. This method does not trigger notifications and can invalidate handles used by other applications. Instead, use the
[SHCopyKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcopykeya) function or the [RegCopyTree](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcopytreea) function.

The calling process must have the SE_BACKUP_NAME privilege enabled. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

> [!NOTE]
> The winreg.h header defines RegSaveKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya)

[RegReplaceKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regreplacekeya)

[RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya)

[RegSaveKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeyexa)

[Registry Files](https://learn.microsoft.com/windows/desktop/SysInfo/registry-files)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)