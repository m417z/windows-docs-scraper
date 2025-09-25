# _KEY_VALUE_INFORMATION_CLASS enumeration

## Description

The **KEY_VALUE_INFORMATION_CLASS** enumeration type specifies the type of information to supply about the value of a registry key.

## Constants

### `KeyValueBasicInformation`

The information is stored as a [KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information) structure.

### `KeyValueFullInformation`

The information is stored as a [KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information) structure.

### `KeyValuePartialInformation`

The information is stored as a [KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information) structure.

### `KeyValueFullInformationAlign64`

The information is stored as a **KEY_VALUE_FULL_INFORMATION** structure that is aligned to a 64-bit (that is, 8-byte) boundary in memory. If the caller-supplied buffer does not start on a 64-bit boundary, [**ZwQueryValueKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey) returns **STATUS_DATATYPE_MISALIGNMENT**.

### `KeyValuePartialInformationAlign64`

The information is stored as a **KEY_VALUE_PARTIAL_INFORMATION_ALIGN64** structure that is aligned to a 64-bit (that is, 8-byte) boundary in memory. If the caller-supplied buffer does not start on a 64-bit boundary, [**ZwQueryValueKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey) returns **STATUS_DATATYPE_MISALIGNMENT**.

### `KeyValueLayerInformation`

### `MaxKeyValueInfoClass`

The maximum value in this enumeration type.

## Remarks

Use the **KEY_VALUE_INFORMATION_CLASS** values to specify the type of data to be supplied by the [ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey) and [ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey) routines.

## See also

[KEY_VALUE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[KEY_VALUE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[KEY_VALUE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)