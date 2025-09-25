# RegCreateKeyExA function

## Description

Creates the specified registry key. If the key already exists, the function opens it. Note that key names are not case sensitive.

To perform transacted registry operations on a key, call the [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda) function.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key. The calling process must have KEY_CREATE_SUB_KEY access to the key. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

Access for key creation is checked against the security descriptor of the registry key, not the access mask specified when the handle was obtained. Therefore, even if *hKey* was opened with a *samDesired* of KEY_READ, it can be used in operations that modify the registry if allowed by its security descriptor.

This handle is returned by the
**RegCreateKeyEx** or
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function, or it can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**

**HKEY_CURRENT_CONFIG**

**HKEY_CURRENT_USER**

**HKEY_LOCAL_MACHINE**

**HKEY_USERS**

### `lpSubKey` [in]

The name of a subkey that this function opens or creates. The subkey specified must be a subkey of the key identified by the *hKey* parameter; it can be up to 32 levels deep in the registry tree. For more information on key names, see [Structure of the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/structure-of-the-registry).

If *lpSubKey* is a pointer to an empty string, *phkResult* receives a new handle to the key specified by *hKey*.

This parameter cannot be **NULL**.

### `Reserved`

This parameter is reserved and must be zero.

### `lpClass` [in, optional]

The user-defined class type of this key. This parameter may be ignored. This parameter can be **NULL**.

### `dwOptions` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **REG_OPTION_BACKUP_RESTORE**<br><br>0x00000004L | If this flag is set, the function ignores the *samDesired* parameter and attempts to open the key with the access required to backup or restore the key. If the calling thread has the SE_BACKUP_NAME privilege enabled, the key is opened with the ACCESS_SYSTEM_SECURITY and KEY_READ access rights. If the calling thread has the SE_RESTORE_NAME privilege enabled, beginning with Windows Vista, the key is opened with the ACCESS_SYSTEM_SECURITY, DELETE and KEY_WRITE access rights. If both privileges are enabled, the key has the combined access rights for both privileges. For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges). |
| **REG_OPTION_CREATE_LINK**<br><br>0x00000002L | **Note** Registry symbolic links should only be used for application compatibility when absolutely necessary.<br><br>This key is a symbolic link. The target path is assigned to the L"SymbolicLinkValue" value of the key. The target path must be an absolute registry path. |
| **REG_OPTION_NON_VOLATILE**<br><br>0x00000000L | This key is not volatile; this is the default. The information is stored in a file and is preserved when the system is restarted. The [RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function saves keys that are not volatile. |
| **REG_OPTION_VOLATILE**<br><br>0x00000001L | All keys created by the function are volatile. The information is stored in memory and is not preserved when the corresponding registry hive is unloaded. For **HKEY_LOCAL_MACHINE**, this occurs only when the system initiates a full shutdown. For registry keys loaded by the [RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya) function, this occurs when the corresponding [RegUnLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regunloadkeya) is performed. The [RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function does not save volatile keys. This flag is ignored for keys that already exist. <br><br> <br><br>**Note** On a user selected shutdown, a fast startup shutdown is the default behavior for the system. |

### `samDesired` [in]

A mask that specifies the access rights for the key to be created. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `lpSecurityAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether the returned handle can be inherited by child processes. If *lpSecurityAttributes* is **NULL**, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new key. If *lpSecurityAttributes* is **NULL**, the key gets a default security descriptor. The ACLs in a default security descriptor for a key are inherited from its direct parent key.

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened or created key. If the key is not one of the predefined registry keys, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function after you have finished using the handle.

### `lpdwDisposition` [out, optional]

A pointer to a variable that receives one of the following disposition values.

| Value | Meaning |
| --- | --- |
| **REG_CREATED_NEW_KEY**<br><br>0x00000001L | The key did not exist and was created. |
| **REG_OPENED_EXISTING_KEY**<br><br>0x00000002L | The key existed and was simply opened without being changed. |

If *lpdwDisposition* is **NULL**, no disposition information is returned.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

The key that the
**RegCreateKeyEx** function creates has no values. An application can use the
[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) function to set key values.

The **RegCreateKeyEx** function creates all missing keys in the specified path. An application can take advantage of this behavior to create several keys at once. For example, an application can create a subkey four levels deep at the same time as the three preceding subkeys by specifying a string of the following form for the *lpSubKey* parameter:

*subkey1\subkey2\subkey3\subkey4*

Note that this behavior will result in creation of unwanted keys if an existing key in the path is spelled incorrectly.

An application cannot create a key that is a direct child of **HKEY_USERS** or **HKEY_LOCAL_MACHINE**. An application can create subkeys in lower levels of the **HKEY_USERS** or **HKEY_LOCAL_MACHINE** trees.

If your service or application impersonates different users, do not use this function with **HKEY_CURRENT_USER**. Instead, call the [RegOpenCurrentUser](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopencurrentuser) function.

Note that operations that access certain registry keys are redirected. For more information, see [Registry Virtualization](https://learn.microsoft.com/windows/desktop/SysInfo/registry-virtualization) and [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

> [!NOTE]
> The winreg.h header defines RegCreateKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa)

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)