# _REG_NOTIFY_CLASS enumeration

## Description

The **REG_NOTIFY_CLASS** enumeration type specifies the type of registry operation that the configuration manager is passing to a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine.

## Constants

### `RegNtDeleteKey`

Specifies that a thread is attempting to delete a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreDeleteKey`

Specifies that a thread is attempting to delete a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtSetValueKey`

Specifies that a thread is attempting to set a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreSetValueKey`

Specifies that a thread is attempting to set a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtDeleteValueKey`

Specifies that a thread is attempting to delete a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreDeleteValueKey`

Specifies that a thread is attempting to delete a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtSetInformationKey`

Specifies that a thread is attempting to set the metadata for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreSetInformationKey`

Specifies that a thread is attempting to set the metadata for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtRenameKey`

Specifies that a thread is attempting to rename a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreRenameKey`

Specifies that a thread is attempting to rename a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtEnumerateKey`

Specifies that a thread is attempting to enumerate a subkey of a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreEnumerateKey`

Specifies that a thread is attempting to enumerate a subkey of a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtEnumerateValueKey`

Specifies that a thread is attempting to enumerate a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreEnumerateValueKey`

Specifies that a thread is attempting to enumerate a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtQueryKey`

Specifies that a thread is attempting to read the metadata for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreQueryKey`

Specifies that a thread is attempting to read the metadata for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtQueryValueKey`

Specifies that a thread is attempting to read a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreQueryValueKey`

Specifies that a thread is attempting to read a value entry for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtQueryMultipleValueKey`

Specifies that a thread is attempting to query multiple value entries for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on only Windows XP.

### `RegNtPreQueryMultipleValueKey`

Specifies that a thread is attempting to query multiple value entries for a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPreCreateKey`

Specifies that a thread is attempting to create a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPostCreateKey`

Specifies that a thread has successfully created a key. This value indicates a post-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreOpenKey`

Specifies that a thread is attempting to open an existing key. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPostOpenKey`

Specifies that a thread has successfully opened an existing key. This value indicates a post-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtKeyHandleClose`

Specifies that a thread is attempting to close a key handle. This value indicates a pre-notification call to *RegistryCallback*. Use this value only on Windows XP.

### `RegNtPreKeyHandleClose`

Specifies that a thread is attempting to close a key handle. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system. Drivers can monitor this registry operation but they cannot block or modify it.

### `RegNtPostDeleteKey`

Specifies that the system has attempted to delete the key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostSetValueKey`

Specifies that the system has attempted to set a value entry for a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostDeleteValueKey`

Specifies that the system has attempted to delete a value entry for a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostSetInformationKey`

Specifies that the system has attempted to set the key's metadata. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostRenameKey`

Specifies that the system has attempted to rename the key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostEnumerateKey`

Specifies that the system has attempted to enumerate the subkey of a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostEnumerateValueKey`

Specifies that the system has attempted to enumerate the value entry of a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostQueryKey`

Specifies that the system has attempted to query the metadata for a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostQueryValueKey`

Specifies that the system has attempted to query a value entry for the key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostQueryMultipleValueKey`

Specifies that the system has attempted to query multiple value entries for the key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostKeyHandleClose`

Specifies that the system has attempted to close a key handle. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPreCreateKeyEx`

Specifies that a thread is attempting to create a key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostCreateKeyEx`

Specifies that the system has attempted to create a key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPreOpenKeyEx`

Specifies that a thread is attempting to open an existing key. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPostOpenKeyEx`

Specifies that the system has attempted to open an existing key. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Server 2003 and later versions of the Windows operating system.

### `RegNtPreFlushKey`

Specifies that a thread is attempting to write a key to disk. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPostFlushKey`

Specifies that the system has attempted to write a key to disk. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPreLoadKey`

Specifies that a thread is attempting to load a registry hive from a file. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPostLoadKey`

Specifies that the system has attempted to load a registry hive from a file. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPreUnLoadKey`

Specifies that a thread is attempting to unload a registry hive. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPostUnLoadKey`

Specifies that the system has attempted to unload a registry hive. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPreQueryKeySecurity`

Specifies that a thread is attempting to obtain a registry key's security information. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPostQueryKeySecurity`

Specifies that a thread has attempted to obtain a registry key's security information. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPreSetKeySecurity`

Specifies that a thread is attempting to set a registry key's security information. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPostSetKeySecurity`

Specifies that a thread has attempted to set a registry key's security information. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtCallbackObjectContextCleanup`

 Specifies that the driver has called [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback) or the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine has just finished processing a **RegNtPreKeyHandleClose** class value. Use this value on Windows Vista and later versions of the Windows operating system.

### `RegNtPreRestoreKey`

Specifies that a thread is attempting to restore a registry key's information. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPostRestoreKey`

Specifies that a thread has attempted to restore a registry key's information. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPreSaveKey`

Specifies that a thread is attempting to save a registry key's information. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPostSaveKey`

Specifies that a thread has attempted to save a registry key's information. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPreReplaceKey`

Specifies that a thread is attempting to replace a registry key's information. This value indicates a pre-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPostReplaceKey`

Specifies that a thread has attempted to replace a registry key's information. This value indicates a post-notification call to *RegistryCallback*. Use this value on Windows Vista SP2 and later versions of the Windows operating system.

### `RegNtPreQueryKeyName`

Specifies that a thread is attempting to obtain the full path of a registry key. Use this value on Windows 10 and later versions of the Windows operating system.

### `RegNtPostQueryKeyName`

Specifies that a thread has attempted to obtain the full path of a registry key. Use this value on Windows 10 and later versions of the Windows operating system.

### `RegNtPreSaveMergedKey`

Specifies that a thread is attempting to save a merged view of two registry subtrees to a file. Use this value on Windows 10 and later versions of the Windows operating system.

### `RegNtPostSaveMergedKey`

Specifies that a thread has attempted to save a merged view of two registry subtrees to a file. Use this value on Windows 10 and later versions of the Windows operating system.

### `MaxRegNtNotifyClass`

Specifies the maximum value in this enumeration type.

## Remarks

When the configuration manager calls a driver's *RegistryCallback* routine, it passes a **REG_NOTIFY_CLASS** enumeration value to the routine. The configuration manager also passes a notification-specific structure that contains information about the notification. For a list of these structures, see [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function).

## See also

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)