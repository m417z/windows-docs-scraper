# RegDeleteKeyA function

## Description

Deletes a subkey and its values. Note that key names are not case sensitive.

**64-bit Windows:** On WOW64, 32-bit applications view a registry tree that is separate from the registry tree that 64-bit applications view. To enable an application to delete an entry in the alternate registry view, use the [RegDeleteKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeyexa) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. The access rights of this key do not affect the delete operation. For more information about access rights, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[Predefined Keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `lpSubKey` [in]

The name of the key to be deleted. It must be a subkey of the key that *hKey* identifies, but it cannot have subkeys. This parameter cannot be **NULL**.

The function opens the subkey with the DELETE access right.

Key names are not case sensitive.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. To get a generic description of the error, you can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag.

## Remarks

A deleted key is not removed until the last handle to it is closed.

The subkey to be deleted must not have subkeys. To delete a key and all its subkeys, you need to enumerate the subkeys and delete them individually. To delete keys recursively, use the
[RegDeleteTree](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletetreea) or [SHDeleteKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shdeletekeya) function.

#### Examples

For an example that uses this function, see [Deleting a Key with Subkeys](https://learn.microsoft.com/windows/desktop/SysInfo/deleting-a-key-with-subkeys).

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

> [!NOTE]
> The winreg.h header defines RegDeleteKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteTree](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletetreea)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)

[SHDeleteEmptyKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shdeleteemptykeya)

[SHDeleteKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shdeletekeya)