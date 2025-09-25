# _KEY_BASIC_INFORMATION structure

## Description

The **KEY_BASIC_INFORMATION** structure defines a subset of the full information that is available for a registry key.

## Members

### `LastWriteTime`

The last time this key or any of its values changed. This time value is expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `NameLength`

The size, in bytes, of the key name string in the **Name** array.

### `Name`

An array of wide characters that contains the name of the registry key. This character string is not null-terminated. Only the first element in this array is included in the **KEY_BASIC_INFORMATION** structure definition. The storage for the remaining elements in the array immediately follows this element.

## Remarks

The [ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey) and [ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey) routines use the **KEY_BASIC_INFORMATION** structure to contain the basic information for a registry key. When the *KeyInformationClass* parameter of either routine is **KeyBasicInformation**, the *KeyInformation* buffer is treated as a **KEY_BASIC_INFORMATION** structure. For more information about the **KeyBasicInformation** enumeration value, see [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class).

## See also

[KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)