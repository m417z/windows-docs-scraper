# IRegistryKey::EnumerateKey

## Description

The `EnumerateKey` method returns information about the subkeys of the open key.

## Parameters

### `Index` [in]

Specifies the subkey index. This parameter identifies the subkey for which key information is requested. If the key contains *n* subkeys, valid indices range from 0 to *n*-1. If the index exceeds this range, the method returns STATUS_NO_MORE_ENTRIES.

### `KeyInformationClass` [in]

Specifies the type of information to be returned in the buffer. Set this parameter to one of the following KEY_INFORMATION_CLASS enumeration values:

* **KeyBasicInformation**
* **KeyFullInformation**
* **KeyNodeInformation**

### `KeyInformation` [out]

Pointer to the key information buffer. This parameter points to a caller-allocated buffer into which the method writes the requested data. The buffer contains a structure of type [KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information), [KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information), or [KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information), depending on the value of *KeyInformationClass*. The structure is followed by a string of Unicode characters whose size depends on the type of information being requested about the key.

### `Length` [in]

Specifies the size in bytes of the *KeyInformation* buffer, which the caller must set according to the given *KeyInformationClass*. For the call to succeed, the buffer must be at least as large as the data that the method writes into the buffer.

### `ResultLength` [out]

Output pointer for the length of the resulting data. This parameter points to a caller-allocated ULONG variable into which the method writes a count specifying the number of bytes actually written into the *KeyInformation* buffer. If the specified buffer length is too small to contain the information, however, the method instead outputs the required buffer size and returns STATUS_BUFFER_OVERFLOW.

## Return value

`EnumerateKey` returns STATUS_SUCCESS if the call was successful in retrieving the requested information in the *KeyInformation* buffer. If the specified buffer size is too small to receive all of the available information, the method returns STATUS_BUFFER_OVERFLOW. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | Indicates that the specified buffer is too small to receive any information. |
| **STATUS_NO_MORE_ENTRIES** | Indicates that no more subkeys are available (subkey index is larger than or equal to the number of subkeys). |

## See also

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)