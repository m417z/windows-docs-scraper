# _KEY_FULL_INFORMATION structure

## Description

The **KEY_FULL_INFORMATION** structure defines the information available for a registry key, including information about its subkeys and the maximum length for their names and value entries. This information can be used to size buffers to get the names of subkeys and their value entries.

## Members

### `LastWriteTime`

The last time this key or any of its values changed. This time value is expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `ClassOffset`

The byte offset from the start of this structure to the **Class** member.

### `ClassLength`

The size, in bytes, of the key class name string in the **Class** array.

### `SubKeys`

The number of subkeys for this key.

### `MaxNameLen`

The maximum size, in bytes, of any name for a subkey.

### `MaxClassLen`

The maximum size, in bytes, of a class name.

### `Values`

The number of value entries for this key.

### `MaxValueNameLen`

The maximum size, in bytes, of a value entry name.

### `MaxValueDataLen`

The maximum size, in bytes, of a value entry data field.

### `Class`

An array of wide characters that contains the name of the class of the key. This character string is not null-terminated. Only the first element in this array is included in the **KEY_FULL_INFORMATION** structure definition. The storage for the remaining elements in the array immediately follows this element.

## Remarks

The [ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey) and [ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey) routines use the **KEY_FULL_INFORMATION** structure to contain the full information for a registry key. When the *KeyInformationClass* parameter of either routine is **KeyFullInformation**, the *KeyInformation* buffer is treated as a **KEY_FULL_INFORMATION** structure. For more information about the **KeyFullInformation** enumeration value, see [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class).

## See also

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)