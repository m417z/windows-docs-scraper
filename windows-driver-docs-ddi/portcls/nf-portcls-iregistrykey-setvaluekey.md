# IRegistryKey::SetValueKey

## Description

The `SetValueKey` method replaces or creates a value entry under the open key.

## Parameters

### `ValueName` [in, optional]

Pointer to a string containing the name of the value entry to set. The name string is specified by a structure of type [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string). If the value entry has no name, set this parameter to **NULL**. If the caller specifies a name string but the given name is not unique relative to its containing key, the method replaces the data for an existing value entry.

### `Type` [in]

Specifies the type of the data to be written for *ValueName*. Set this parameter to one of the following system-defined types:

REG_BINARY

REG_DWORD

REG_DWORD_LITTLE_ENDIAN

REG_DWORD_BIG_ENDIAN

REG_EXPAND_SZ

REG_LINK

REG_MULTI_SZ

REG_NONE

REG_SZ

REG_RESOURCE_LIST

REG_RESOURCE_REQUIREMENTS_LIST

REG_FULL_RESOURCE_DESCRIPTOR

These parameter types are explained in [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

### `Data` [in]

Pointer to a buffer containing the data. This parameter points to a user-supplied structure or value appropriate to the function.

### `DataSize` [in]

Specifies the size in bytes of *Data*. This parameter specifies how many bytes of data the method will copy from the buffer that *Data* points to.

## Return value

`SetValueKey` returns STATUS_SUCCESS if the call was successful in setting the specified value key. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameters passed to the method is not valid. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | Indicates that method was unable to find the named value key. |

## Remarks

If the given key has no existing value entry with a name matching the given *ValueName*, `SetValueKey` creates a new value entry with the given name. If a matching value entry name exists, this routine overwrites the original value entry for the given *ValueName*. Thus, `SetValueKey` preserves a unique name for each value entry of any particular key. While each value entry name must be unique to its containing key, many different keys in the registry can have value entries with the same names.

## See also

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)