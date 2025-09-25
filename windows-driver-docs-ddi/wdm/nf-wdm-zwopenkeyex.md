# ZwOpenKeyEx function

## Description

The **ZwOpenKeyEx** routine opens an existing registry key.

## Parameters

### `KeyHandle` [out]

A pointer to a HANDLE variable into which the routine writes the handle to the key.

### `DesiredAccess` [in]

Specifies the type of access to the key that the caller requests. This parameter is an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value. For more information, see the description of the *DesiredAccess* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine.

### `ObjectAttributes` [in]

A pointer to the object attributes of the key being opened. This parameter points to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that must have been previously initialized by the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) routine. The caller must specify the name of the registry key as the *ObjectName* parameter in the call to **InitializeObjectAttributes**. If the caller is not running in a system thread context, it must set the OBJ_KERNEL_HANDLE attribute when it calls **InitializeObjectAttributes**.

### `OpenOptions` [in]

Specifies the options to apply when opening the key. Set this parameter to zero or to the bitwise OR of one or more of the following REG_OPTION_*XXX* flag bits:

| *OpenOptions* flag | Description |
| --- | --- |
| REG_OPTION_OPEN_LINK | The key is a symbolic link. This flag is not used by device and intermediate drivers. |
| REG_OPTION_BACKUP_RESTORE | The key should be opened with special privileges that allow backup and restore operations. This flag is not used by device and intermediate drivers. |

## Return value

**ZwOpenKeyEx** returns STATUS_SUCCESS if the call succeeds in opening the key. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_4** | The *OpenOptions* parameter specifies invalid options. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The registry path in the object attributes is invalid. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry key name in the object attributes was not found. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The named registry key is a symbolic link, but the REG_OPTION_OPEN_LINK flag bit is not set in *OpenOptions*. |
| **STATUS_ACCESS_DENIED** | The caller did not have the required access rights to open a handle for the named registry key. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation operation failed. |

## Remarks

This routine supplies a handle with which the caller can access a registry key. If the specified key does not exist, the routine returns an error status value and does not supply a key handle.

The [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey) routine is similar to **ZwOpenKeyEx** but does not accept an *OpenOptions* parameter. The *OpenOptions* parameter of **ZwOpenKeyEx** enables the caller to open a key that is a symbolic link, or to open a key for backup and restore operations. A call to **ZwOpenKeyEx** with *OpenOptions* = 0 is equivalent to a call to **ZwOpenKey**.

After the handle pointed to by *KeyHandle* is no longer in use, the driver must call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) to close it.

**ZwOpenKeyEx** ignores the security information in the structure that the *ObjectAttributes* parameter points to.

If the kernel-mode caller is not running in a system thread context, it must ensure that any handles it creates are kernel handles. Otherwise, the handle can be accessed by the process in whose context the driver is running. For more information, see [Object Handles](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-handles).

For more information about working with registry keys in kernel mode, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)