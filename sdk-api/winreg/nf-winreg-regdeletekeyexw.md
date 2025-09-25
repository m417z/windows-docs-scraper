# RegDeleteKeyExW function

## Description

Deletes a subkey and its values from the specified platform-specific view of the registry. Note that key names are not case sensitive.

To delete a subkey as a transacted operation, call the [RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeytransacteda) function.

## Parameters

### `hKey` [in]

A handle to an open registry key. The access rights of this key do not affect the delete operation. For more information about access rights, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `lpSubKey` [in]

The name of the key to be deleted. This key must be a subkey of the key specified by the value of the *hKey* parameter.

The function opens the subkey with the DELETE access right.

Key names are not case sensitive.

The value of this parameter cannot be **NULL**.

### `samDesired` [in]

An access mask the specifies the platform-specific view of the registry.

| Value | Meaning |
| --- | --- |
| **KEY_WOW64_32KEY**<br><br>0x0200 | Delete the key from the 32-bit registry view. |
| **KEY_WOW64_64KEY**<br><br>0x0100 | Delete the key from the 64-bit registry view. |

### `Reserved`

This parameter is reserved and must be zero.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

A deleted key is not removed until the last handle to it is closed.

On WOW64, 32-bit applications view a registry tree that is separate from the registry tree that 64-bit applications view. This function enables an application to delete an entry in the alternate registry view.

The subkey to be deleted must not have subkeys. To delete a key and all its subkeys, you need to enumerate the subkeys and delete them individually. To delete keys recursively, use the
[RegDeleteTree](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletetreea) or [SHDeleteKey](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shdeletekeya) function.

If the function succeeds, **RegDeleteKeyEx** removes the specified key from the registry. The entire key, including all of its values, is removed.

> [!NOTE]
> On legacy versions of Windows, this API is also exposed by kernel32.dll.

> [!NOTE]
> The winreg.h header defines RegDeleteKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeytransacteda)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Redirector](https://learn.microsoft.com/windows/desktop/WinProg64/registry-redirector)