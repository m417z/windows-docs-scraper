# _KEY_VALUE_ENTRY structure

## Description

The **KEY_VALUE_ENTRY** structure is used by the [REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information) structure to describe a single value entry for a registry key.

## Members

### `ValueName`

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the value entry.

### `DataLength`

Specifies the size, in bytes, of the data for the value entry.

### `DataOffset`

Specifies the offset, in bytes, of the value entry's data within the buffer that is pointed to by the **ValueBuffer** member of [REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information).

### `Type`

Specifies the type of the value entry's data. For a description of the possible values for **Type**, see the *Type* parameter of [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

## Remarks

The **ValueEntries** member of [REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information) points to an array of KEY_VALUE_ENTRY structures.

## See also

[REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)