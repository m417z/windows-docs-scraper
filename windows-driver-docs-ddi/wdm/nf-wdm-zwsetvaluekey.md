## Description

The **ZwSetValueKey** routine creates or replaces a registry key's value entry.

## Parameters

### `KeyHandle` [in]

Handle to the registry key to write a value entry for. This handle is created by a successful call to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

### `ValueName` [in]

Pointer to the name of the value entry for which the data is to be written. This parameter can be a **NULL** pointer if the value entry has no name. If a name string is specified and the given name is not unique relative to its containing key, the data for an existing value entry is replaced.

### `TitleIndex` [in, optional]

This parameter is reserved. Device and intermediate drivers should set this parameter to zero.

### `Type` [in]

One of the following system-defined types of data to write:

| *Type* value | Meaning |
|---|---|
| REG_BINARY | Binary data in any form. |
| REG_DWORD | A 4-byte numerical value. |
| REG_DWORD_LITTLE_ENDIAN | A 4-byte numerical value with the least significant byte at the lowest address. Identical to REG_DWORD. |
| REG_DWORD_BIG_ENDIAN | A 4-byte numerical value with the least significant byte at the highest address. |
| REG_EXPAND_SZ | A null-terminated Unicode string that contains unexpanded references to environment variables, such as "%PATH%". |
| REG_LINK | A Unicode string that names a symbolic link. This type is irrelevant to device and intermediate drivers. |
| REG_MULTI_SZ | An array of null-terminated strings, terminated by another zero. |
| REG_NONE | Data with no particular type. |
| REG_SZ | A null-terminated Unicode string. |
| REG_RESOURCE_LIST | A device driver's list of hardware resources, used by the driver or one of the physical devices it controls, in the **\ResourceMap** tree |
| REG_RESOURCE_REQUIREMENTS_LIST | A device driver's list of possible hardware resources it or one of the physical devices it controls can use, from which the system writes a subset into the **\ResourceMap** tree |
| REG_FULL_RESOURCE_DESCRIPTOR | A list of hardware resources that a physical device is using, detected and written into the **\HardwareDescription** tree by the system |

Device drivers should not attempt to call **ZwSetValueKey** to explicitly write value entries in a subkey of the **\Registry...\ResourceMap** key. Only the system can write value entries to the **\Registry...\HardwareDescription** tree.

### `Data` [in, optional]

Pointer to a caller-allocated buffer that contains the data for the value entry.

### `DataSize` [in]

Specifies the size, in bytes, of the *Data* buffer. If *Type* is REG_*XXX*_SZ, this value must include space for any terminating zeros.

## Return value

**ZwSetValueKey** returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
|---|---|
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the registry value. |
| **STATUS_INVALID_HANDLE** | The handle is invalid. |

## Remarks

The *KeyHandle* passed to **ZwSetValueKey** must have been opened with the KEY_SET_VALUE *DesiredAccess* flag set for this call to succeed. For a description of possible values for *DesiredAccess*, see [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey).

If the given key has no existing value entry with a name matching the given *ValueName*, **ZwSetValueKey** creates a new value entry with the given name. If a matching value entry name exists, this routine overwrites the original value entry for the given *ValueName*. Thus, **ZwSetValueKey** preserves a unique name for each value entry of any particular key. While each value entry name must be unique to its containing key, many different keys in the registry can have value entries with the same names.

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "NtSetValueKey" instead of "**ZwSetValueKey**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[IoAssignResources](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwFlushKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwflushkey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)