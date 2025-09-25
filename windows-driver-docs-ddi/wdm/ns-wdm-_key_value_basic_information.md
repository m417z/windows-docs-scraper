# _KEY_VALUE_BASIC_INFORMATION structure

## Description

The **KEY_VALUE_BASIC_INFORMATION** structure defines a subset of the full information available for a value entry of a registry key.

## Members

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `Type`

Specifies the system-defined type for the value entry in the registry key, which is one of the following:

| REG_*XXX* type | Value |
| --- | --- |
| REG_BINARY | Binary data in any form |
| REG_DWORD | A 4-byte numerical value |
| REG_DWORD_LITTLE_ENDIAN | A 4-byte numerical value whose least significant byte is at the lowest address |
| REG_DWORD_BIG_ENDIAN | A 4-byte numerical value whose least significant byte is at the highest address |
| REG_EXPAND_SZ | A null-terminated Unicode string, containing unexpanded references to environment variables, such as "%PATH%" |
| REG_LINK | A Unicode string naming a symbolic link. This type is irrelevant to device and intermediate drivers |
| REG_MULTI_SZ | An array of null-terminated strings, terminated by another zero |
| REG_NONE | Data with no particular type |
| REG_SZ | A null-terminated Unicode string |
| REG_RESOURCE_LIST | A device driver's list of hardware resources, used by the driver or one of the physical devices it controls, in the **\ResourceMap** tree | |
| REG_RESOURCE_REQUIREMENTS_LIST | A device driver's list of possible hardware resources it or one of the physical devices it controls can use, from which the system writes a subset into the **\ResourceMap** tree | |
| REG_FULL_RESOURCE_DESCRIPTOR | A list of hardware resources that a physical device is using, detected and written into the **\HardwareDescription** tree by the system | |
| REG_QWORD | An 8-byte numerical value |
| REG_QWORD_LITTLE_ENDIAN | An 8-byte numerical value whose least significant byte is at the lowest address |

### `NameLength`

Specifies the size in bytes of the following value entry name.

### `Name`

A string of Unicode characters naming a value entry of the key.

## Remarks

A kernel-mode driver can obtain a **KEY_VALUE_BASIC_INFORMATION** that describes a registry key by calling the [ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey) or [ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey) routine.

## See also

[KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class)

[KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)