# _KEY_CACHED_INFORMATION structure

## Description

The **KEY_CACHED_INFORMATION** structure holds the cached information available for a registry key or subkey.

## Members

### `LastWriteTime`

The last time the key or any of its values changed. This time value is expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `SubKeys`

The number of subkeys for a key.

### `MaxNameLen`

The maximum number of bytes for a subkey name.

### `Values`

The number of value entries.

### `MaxValueNameLen`

The maximum length, in bytes, of any value entry name.

### `MaxValueDataLen`

The maximum length, in bytes, of a value entry data field.

### `NameLength`

The size, in bytes, of the key name.

## See also

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)