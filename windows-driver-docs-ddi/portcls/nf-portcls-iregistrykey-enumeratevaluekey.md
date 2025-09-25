# IRegistryKey::EnumerateValueKey

## Description

The `EnumerateValueKey` method returns information about a registry entry that contains a value key.

## Parameters

### `Index` [in]

Specifies the subkey index. This parameter identifies the subkey whose value is requested. If the key contains *n* subkeys, valid indices range from 0 to *n*-1. If the index exceeds this range, the method returns STATUS_NO_MORE_ENTRIES.

### `KeyValueInformationClass` [in]

Specifies the type of information to be returned in the buffer. Set this parameter to one of the following KEY_VALUE_INFORMATION_CLASS enumeration values:

* **KeyValueBasicInformation**
* `KeyValueFullInformation`
* `KeyValuePartialInformation`

### `KeyValueInformation` [out]

Output pointer for the key value. This parameter points to a caller-allocated buffer into which the method writes the requested data. The buffer contains a structure of type [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information), [KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information), or [KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information), depending on the value of *KeyValueInformationClass*. The structure is followed by additional data whose size depends on the data type of the key value.

### `Length` [in]

Size in bytes of the *KeyValueInformation* buffer, which the caller must set according to the given *KeyValueInformationClass*. For the call to succeed, the buffer must be at least as large as the data that the method writes into the buffer.

### `ResultLength` [out]

Output pointer for the length of the resulting data. This parameter points to a caller-allocated ULONG variable into which the method writes a count specifying the number of bytes actually written into the *KeyValueInformation* buffer. If the specified buffer length is too small to contain the information, however, the method instead outputs the required buffer size and returns STATUS_BUFFER_OVERFLOW.

## Return value

`EnumerateValueKey` returns STATUS_SUCCESS if the call was successful in copying the requested information into the *KeyValueInformation* buffer. If the specified buffer size is too small to receive all of the available information, the method returns STATUS_BUFFER_OVERFLOW. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | Indicates that the specified buffer is too small to receive any information. |
| **STATUS_INVALID_PARAMETER** | Indicates that one of the parameters passed to the method is not valid. |
| **STATUS_NO_MORE_ENTRIES** | Indicates that no more value keys are available (the *Index* parameter is greater than or equal to the number of value keys). |

## See also

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)