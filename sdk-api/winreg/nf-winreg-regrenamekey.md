## Description

Changes the name of the specified registry key.

## Parameters

### `hKey`

A handle to the key to be renamed. The handle must be opened with the KEY_WRITE access right. For more information, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/win32/SysInfo/registry-key-security-and-access-rights).

This handle is returned by the [RegCreateKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following [Predefined Keys](https://learn.microsoft.com/windows/win32/SysInfo/predefined-keys):

* HKEY_CLASSES_ROOT
* HKEY_CURRENT_CONFIG
* HKEY_CURRENT_USER
* HKEY_LOCAL_MACHINE
* HKEY_USERS

### `lpSubKeyName`

The name of the subkey to be renamed. This key must be a subkey of the key identified by the *hKey* parameter. This parameter can also be **NULL**, in which case the key identified by the *hKey* parameter will be renamed.

### `lpNewKeyName`

The new name of the key. The new name must not already exist.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error. An error code of STATUS_ACCESS_DENIED indicates that the caller does not have the necessary access rights to the specified registry key or subkeys.

## Remarks

This function can be used to rename an entire registry subtree. The caller must have KEY_CREATE_SUB_KEY access to the parent of the specified key and DELETE access to the entire subtree being renamed.

## See also

[RegCopyTree](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcopytreew)

[Registry Functions](https://learn.microsoft.com/windows/win32/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/win32/SysInfo/registry)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)