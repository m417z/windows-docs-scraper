# RtlWriteRegistryValue function

## Description

The **RtlWriteRegistryValue** routine writes caller-supplied data into the registry along the specified relative path at the given value name.

## Parameters

### `RelativeTo` [in]

Specifies whether *Path* is an absolute registry path or is relative to a predefined path as one of the following.

| Value | Meaning |
| --- | --- |
| RTL_REGISTRY_ABSOLUTE | Path is an absolute registry path. |
| RTL_REGISTRY_SERVICES | Path is relative to **\Registry\Machine\System\CurrentControlSet\Services**. |
| RTL_REGISTRY_CONTROL | Path is relative to **\Registry\Machine\System\CurrentControlSet\Control**. |
| RTL_REGISTRY_WINDOWS_NT | Path is relative to **\Registry\Machine\Software\Microsoft\Windows NT\CurrentVersion**. |
| RTL_REGISTRY_DEVICEMAP | Path is relative to **\Registry\Machine\Hardware\DeviceMap**. |
| RTL_REGISTRY_USER | Path is relative to **\Registry\User\CurrentUser**. (For a system process, this is **\Users\.Default**.) |
| RTL_REGISTRY_OPTIONAL | Specifies that the key referenced by this parameter and the *Path* parameter are optional. |
| RTL_REGISTRY_HANDLE | Specifies that the *Path* parameter is actually a registry handle to use. This value is optional. |

### `Path` [in]

Pointer to either an absolute registry path or a path relative to the known location specified by the *RelativeTo* parameter. If the RTL_REGISTRY_HANDLE flag is specified, this parameter is a registry handle for an already opened key to be used directly.

### `ValueName` [in]

Pointer to the name of a subkey or value entry to be written into the registry.

### `ValueType` [in]

Specifies a REG_*XXX* value that determines the type of the *ValueName* parameter. For a list of the possible values, see the *Type* parameter of [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

### `ValueData` [in, optional]

Pointer to the name of a subkey or values for its value entries (or both) to be written into the registry.

### `ValueLength` [in]

Specifies the number of bytes of *ValueData* to be written into the registry.

## Return value

**RtlWriteRegistryValue** returns the status of the operation, either STATUS_SUCCESS or an error status.

## Remarks

If the specified key does not exist, the routine attempts to create the key. For this attempt to succeed, the new key must be a direct subkey of the key that is referred to by the *Path* parameter, and the key that *Path* refers to must have been opened for KEY_CREATE_SUB_KEY access.

## See also

[RtlCheckRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckregistrykey)

[RtlCreateRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreateregistrykey)

[RtlDeleteRegistryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtldeleteregistryvalue)

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)