# RegCreateKeyW function

## Description

Creates the specified registry key. If the key already exists in the registry, the function opens it.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) function. However, applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key. The calling process must have KEY_CREATE_SUB_KEY access to the key. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

Access for key creation is checked against the security descriptor of the registry key, not the access mask specified when the handle was obtained. Therefore, even if *hKey* was opened with a *samDesired* of KEY_READ, it can be used in operations that create keys if allowed by its security descriptor.

This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `lpSubKey` [in, optional]

The name of a key that this function opens or creates. This key must be a subkey of the key identified by the *hKey* parameter.

For more information on key names, see [Structure of the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/structure-of-the-registry).

If *hKey* is one of the predefined keys, *lpSubKey* may be **NULL**. In that case, *phkResult* receives the same *hKey* handle passed in to the function.

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened or created key. If the key is not one of the predefined registry keys, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function after you have finished using the handle.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

An application cannot create a key that is a direct child of **HKEY_USERS** or **HKEY_LOCAL_MACHINE**. An application can create subkeys in lower levels of the **HKEY_USERS** or **HKEY_LOCAL_MACHINE** trees.

If your service or application impersonates different users, do not use this function with **HKEY_CURRENT_USER**. Instead, call the [RegOpenCurrentUser](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopencurrentuser) function.

The **RegCreateKey** function creates all missing keys in the specified path. An application can take advantage of this behavior to create several keys at once. For example, an application can create a subkey four levels deep at the same time as the three preceding subkeys by specifying a string of the following form for the *lpSubKey* parameter:

*subkey1\subkey2\subkey3\subkey4*

Note that this behavior will result in creation of unwanted keys if an existing key in the path is spelled incorrectly.

> [!NOTE]
> The winreg.h header defines RegCreateKey as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)