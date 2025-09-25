# IRegistryKey::QueryValueKey

## Description

The `QueryValueKey` method retrieves information about a registry key's value entries, including their names, types, data sizes, and values.

## Parameters

### `ValueName` [in]

Pointer to the manufacturer-supplied name of the value entry. The name string is specified by a structure of type [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string).

### `KeyValueInformationClass` [in]

Specifies the type of information to be returned in the buffer. Set this parameter to one of the following KEY_VALUE_INFORMATION_CLASS enumeration values:

* **KeyValueBasicInformation**
* **KeyValueFullInformation**
* **KeyValuePartialInformation**

### `KeyValueInformation` [out]

Pointer to a caller-allocated buffer into which the method writes the requested data. The buffer contains a structure of type [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information), [KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information), or [KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information), depending on the value of *KeyValueInformationClass*. The structure is followed by additional data whose size depends on the data type of the key value.

### `Length` [in]

Size in bytes of the *KeyValueInformation* buffer, which the caller must set according to the given *KeyValueInformationClass*. To receive all the requested data, the buffer must be at least as large as the size of the requested data.

### `ResultLength` [out]

Output pointer for the length of the resulting data. This parameter points to a caller-allocated ULONG variable into which the method writes a count specifying the number of bytes actually written into the *KeyValueInformation* buffer. If the specified buffer length is too small to contain the information, however, the method instead outputs the required buffer size and returns STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL. For more information, see the following Remarks section.

## Return value

`QueryValueKey` returns STATUS_SUCCESS if the call was successful in copying the requested information to the *KeyValueInformation* buffer. If the specified buffer size is too small to receive all of the requested information, the method returns STATUS_BUFFER_OVERFLOW. If the specified buffer size is too small to receive any of the requested information, the method returns STATUS_BUFFER_TOO_SMALL. Otherwise, the method returns an appropriate error status code. The following table shows some of the possible error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameters passed to the method is not valid. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | Indicates that the value entry with the specified name was not found. |

## Remarks

If the *KeyValueInformation* buffer is too small to hold the requested information, the method writes the required size to **ResultLength* and returns a status code of either STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL. The method returns STATUS_BUFFER_OVERFLOW if it succeeded in writing only part of the requested information to the buffer. The method returns STATUS_BUFFER_TOO_SMALL if it was unable to write any information to the buffer. The value written to **ResultLength* indicates the minimum buffer size required to hold all the requested information.

## See also

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)