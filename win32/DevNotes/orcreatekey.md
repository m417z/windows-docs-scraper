# ORCreateKey function

Creates the specified registry key in an offline registry hive. If the key already exists, the function opens it.

## Parameters

*Handle* \[in\]

A handle to an open registry key in an offline registry hive.

*lpSubKey* \[in\]

A pointer to a Unicode string that contains the name of a subkey that this function opens or creates. The *lpSubKey* parameter must specify a subkey of the key identified by the *Handle* parameter; it can be up to 32 levels deep in the registry tree. For more information about key names, see [Structure of the Registry](https://learn.microsoft.com/windows/win32/sysinfo/structure-of-the-registry).

This parameter cannot be **NULL**.

Key names are not case sensitive.

*lpClass* \[in, optional\]

The class (object type) of this key. This parameter may be ignored. This parameter can be **NULL**.

*dwOptions* \[in, optional\]

This parameter can be 0 or one of the following values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **REG\_OPTION\_CREATE\_LINK**

0x00000002L | The key is a symbolic link. The target path is assigned to the L"SymbolicLinkValue" value of the key. The target path must be an absolute registry path. If this option is set, **REG\_OPTION\_NON\_VOLATILE** must also be set. \ If the *lpSubKey* parameter specifies an existing key, it must have been created with **REG\_OPTION\_CREATE\_LINK**.\ Registry symbolic links should be used only when absolutely necessary for application compatibility. \ | | **REG\_OPTION\_NON\_VOLATILE**

0x00000000L | The key is not volatile; this is the default. The information is stored in a file and is preserved when the system is restarted. The [**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive) function saves keys that are not volatile.\ |

*pSecurityDescriptor* \[in, optional\]

A pointer to a [SECURITY\_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure that contains a security descriptor for the new key. If *pSecurityDescriptor* is **NULL**, the key gets a default security descriptor. The ACLs in a default security descriptor for a key are inherited from its direct parent key.

*phkResult* \[out\]

A pointer to a variable that receives a handle to the opened or created key. Use the [**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey) function to close the key after you have finished using the handle.

*pdwDisposition* \[out, optional\]

A pointer to a variable that receives one of the following disposition values.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **REG\_CREATED\_NEW\_KEY**

0x00000001L | The key did not exist and was created.\ | | **REG\_OPENED\_EXISTING\_KEY**

0x00000002L | The key existed and was simply opened without being changed.\ | If *pdwDisposition* is **NULL**, no disposition information is returned.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If the *dwOptions* parameter is set with **REG\_OPTION\_CREATE\_LINK** but **REG\_OPTION\_NON\_VOLATILE** is clear, or if the handle to be returned would be a handle to the root key of the hive, the function returns ERROR\_INVALID\_PARAMETER.

## Remarks

The key that the **ORCreateKey** function creates has no values. An application can use the [**ORSetValue**](https://learn.microsoft.com/windows/win32/devnotes/orsetvalue) function to set key values.

The **ORCreateKey** function cannot be used to create the root key in an offline registry hive. Use the [**ORCreateHive**](https://learn.microsoft.com/windows/win32/devnotes/orcreatehive) function to create the root key and obtain a handle to the key.

The offline registry does not support saving individual keys. Use the [**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive) function to save a key and its subkeys in a hive.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCloseKey**](https://learn.microsoft.com/windows/win32/devnotes/orclosekey)

[**ORCreateHive**](https://learn.microsoft.com/windows/win32/devnotes/orcreatehive)

[**ORDeleteKey**](https://learn.microsoft.com/windows/win32/devnotes/ordeletekey)

[**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive)

[SECURITY\_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor)

