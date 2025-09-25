## Description

The **ZwCreateKey** routine creates a new registry key or opens an existing one.

## Parameters

### `KeyHandle` [out]

Pointer to a HANDLE variable that receives a handle to the key.

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the object. In addition to the access rights that are defined for all types of objects (see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)), the caller can specify one or more of the following access rights, which are specific to object directories:

| *DesiredAccess* flag | Allows caller to do this |
|---|---|
| KEY_QUERY_VALUE | Read key values. |
| KEY_SET_VALUE | Write key values. |
| KEY_CREATE_SUB_KEY | Create subkeys for the key. |
| KEY_ENUMERATE_SUB_KEYS | Read the key's subkeys. |
| KEY_CREATE_LINK | Create a symbolic link to the key. This flag is not used by device and intermediate drivers. |
| KEY_NOTIFY | Ask to receive notification when the name, value, or attributes of the key change. For more information, see [ZwNotifyChangeKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwnotifychangekey). |

The caller can also specify one of the following constants, which combines several ACCESS_MASK flags.

| Constant | Consists of these ACCESS_MASK flags |
|---|---|
| KEY_READ | STANDARD_RIGHTS_READ, KEY_QUERY_VALUE, KEY_ENUMERATE_SUB_KEYS, and KEY_NOTIFY |
| KEY_WRITE | STANDARD_RIGHTS_WRITE, KEY_SET_VALUE, and KEY_CREATE_SUB_KEY |
| KEY_EXECUTE | Same as KEY_READ. |
| KEY_ALL_ACCESS | STANDARD_RIGHTS_ALL, KEY_QUERY_VALUE, KEY_SET_VALUE, KEY_CREATE_SUB_KEY, KEY_ENUMERATE_SUB_KEYS, KEY_NOTIFY, and KEY_CREATE_LINK |

### `ObjectAttributes` [in]

Pointer to an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies the object name and other attributes. Use [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) to initialize this structure. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `TitleIndex`

Device and intermediate drivers set this parameter to zero.

### `Class` [in, optional]

Pointer to a Unicode string that contains the key's object class. This information is used by the configuration manager.

### `CreateOptions` [in]

Specifies the options to apply when creating or opening a key, specified as a compatible combination of the following flags.

| *CreateOptions* flag | Description |
|---|---|
| REG_OPTION_VOLATILE | Key is not preserved when the system is rebooted. |
| REG_OPTION_NON_VOLATILE | Key is preserved when the system is rebooted. |
| REG_OPTION_CREATE_LINK | The newly created key is a symbolic link. This flag is not used by device and intermediate drivers. |
| REG_OPTION_BACKUP_RESTORE | Key should be created or opened with special privileges that allow backup and restore operations. This flag is not used by device and intermediate drivers. |

### `Disposition` [out, optional]

Pointer to a variable that receives a value indicating whether a new key was created or an existing one opened.

| *Disposition* value | Description |
|---|---|
| REG_CREATED_NEW_KEY | A new key was created. |
| REG_OPENED_EXISTING_KEY | An existing key was opened. |

## Return value

**ZwCreateKey** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error code on failure.

## Remarks

**ZwCreateKey** supplies a handle that the caller can use to manipulate a registry key. For more information, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

Once the handle pointed to by *KeyHandle* is no longer in use, the driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

There are two alternate ways to specify the name of the file to be created or opened with **ZwCreateKey**:

1. As a fully qualified pathname, supplied in the **ObjectName** member of the input *ObjectAttributes*. The pathnames of registry keys begin with **\Registry**.

1. As pathname relative to another registry key, represented by the handle in the **RootDirectory** member of the input *ObjectAttributes*.

If the key specified by *ObjectAttributes* does not exist, the routine attempts to create the key. For this attempt to succeed, the new key must be a direct subkey of the key that is referred to by **RootDirectory**, and the key that **RootDirectory** refers to must have been opened for KEY_CREATE_SUB_KEY access.

If the specified key already exists, it is opened and its value is not affected in any way.

The security attributes specified by *ObjectAttributes* when a key is created determine whether the specified *DesiredAccess* is granted on subsequent calls to **ZwCreateKey** and [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

If the caller is not running in a system thread context, it must ensure that any handles it creates are private handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "**NtCreateKey**" instead of "**ZwCreateKey**".

The **NtCreateKey** routine in the Windows kernel is not directly accessible to kernel-mode drivers.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwDeleteKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwdeletekey)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)

[ZwFlushKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwflushkey)

[ZwNotifyChangeKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwnotifychangekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)