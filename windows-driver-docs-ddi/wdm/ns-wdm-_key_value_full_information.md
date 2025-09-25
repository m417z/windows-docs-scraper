# _KEY_VALUE_FULL_INFORMATION structure

## Description

The **KEY_VALUE_FULL_INFORMATION** structure defines information available for a value entry of a registry key.

## Members

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `Type`

Specifies the system-defined type for the registry value(s) following the **Name** member. For a summary of these types, see [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information).

### `DataOffset`

Specifies the offset from the start of this structure to the data immediately following the **Name** string.

### `DataLength`

Specifies the number of bytes of registry information for the value entry identified by **Name**.

### `NameLength`

Specifies the size in bytes of the following value entry name.

### `Name`

A string of Unicode characters naming a value entry of the key.

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class)

[KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)