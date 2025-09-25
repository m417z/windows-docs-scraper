# RegCreateKeyTransactedA function

## Description

Creates the specified registry key and associates it with a transaction. If the key already exists, the function opens it. Note that key names are not case sensitive.

 Applications that back up or restore system state including system files and registry hives should use the [Volume Shadow Copy Service](https://learn.microsoft.com/windows/win32/vss/volume-shadow-copy-service-overview) instead of the registry functions.

## Parameters

### `hKey` [in]

A handle to an open registry key. The calling process must have KEY_CREATE_SUB_KEY access to the key. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

Access for key creation is checked against the security descriptor of the registry key, not the access mask specified when the handle was obtained. Therefore, even if *hKey* was opened with a *samDesired* of KEY_READ, it can be used in operations that create keys if allowed by its security descriptor.

This handle is returned by the
**RegCreateKeyTransacted** or
[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) function, or it can be one of the following
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

The user-defined class of this key. This parameter may be ignored. This parameter can be **NULL**.

### `dwOptions` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **REG_OPTION_BACKUP_RESTORE**<br><br>0x00000004L | If this flag is set, the function ignores the *samDesired* parameter and attempts to open the key with the access required to backup or restore the key. If the calling thread has the SE_BACKUP_NAME privilege enabled, the key is opened with the ACCESS_SYSTEM_SECURITY and KEY_READ access rights. If the calling thread has the SE_RESTORE_NAME privilege enabled, the key is opened with the ACCESS_SYSTEM_SECURITY and KEY_WRITE access rights. If both privileges are enabled, the key has the combined access rights for both privileges. For more information, see [Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges). |
| **REG_OPTION_NON_VOLATILE**<br><br>0x00000000L | This key is not volatile; this is the default. The information is stored in a file and is preserved when the system is restarted. The [RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function saves keys that are not volatile. |
| **REG_OPTION_VOLATILE**<br><br>0x00000001L | All keys created by the function are volatile. The information is stored in memory and is not preserved when the corresponding registry hive is unloaded. For **HKEY_LOCAL_MACHINE**, this occurs when the system is shut down. For registry keys loaded by the [RegLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadkeya) function, this occurs when the corresponding [RegUnLoadKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regunloadkeya) is performed. The [RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya) function does not save volatile keys. This flag is ignored for keys that already exist. |

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

### `hTransaction` [in]

A handle to an active transaction. This handle is returned by the [CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

### `pExtendedParemeter`

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

When a key is created using this function, subsequent operations on the key are transacted. If a non-transacted operation is performed on the key before the transaction is committed, the transaction is rolled back. After a transaction is committed or rolled back, you must re-open the key using **RegCreateKeyTransacted** or [RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda) with an active transaction handle to make additional operations transacted. For more information about transactions, see [Kernel Transaction Manager](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-portal).

Note that subsequent operations on subkeys of this key are not automatically transacted. Therefore, [RegDeleteKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeyexa) does not perform a transacted delete operation. Instead, use the [RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeytransacteda) function to perform a transacted delete operation.

The key that the
**RegCreateKeyTransacted** function creates has no values. An application can use the
[RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) function to set key values.

The **RegCreateKeyTransacted** function creates all missing keys in the specified path. An application can take advantage of this behavior to create several keys at once. For example, an application can create a subkey four levels deep at the same time as the three preceding subkeys by specifying a string of the following form for the *lpSubKey* parameter:

*subkey1\subkey2\subkey3\subkey4*

Note that this behavior will result in creation of unwanted keys if an existing key in the path is spelled incorrectly.

An application cannot create a key that is a direct child of **HKEY_USERS** or **HKEY_LOCAL_MACHINE**. An application can create subkeys in lower levels of the **HKEY_USERS** or **HKEY_LOCAL_MACHINE** trees.

> [!NOTE]
> The winreg.h header defines RegCreateKeyTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeytransacteda)

[RegOpenKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeytransacteda)

[RegSaveKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsavekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)