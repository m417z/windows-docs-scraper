# _KEY_VALUE_PARTIAL_INFORMATION structure

## Description

The **KEY_VALUE_PARTIAL_INFORMATION** structure defines a subset of the value information available for a value entry of a registry key.

## Members

### `TitleIndex`

Device and intermediate drivers should ignore this member.

### `Type`

Specifies the system-defined type for the registry value in the **Data** member. For a summary of these types, see [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information).

### `DataLength`

The size in bytes of the **Data** member.

### `Data`

A value entry of the key.

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)