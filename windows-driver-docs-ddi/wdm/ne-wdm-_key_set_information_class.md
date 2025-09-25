# _KEY_SET_INFORMATION_CLASS enumeration

## Description

The **KEY_SET_INFORMATION_CLASS** enumeration type represents the type of information to set for a registry key.

## Constants

### `KeyWriteTimeInformation`

Indicates that a [KEY_WRITE_TIME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_write_time_information) structure is supplied.

### `KeyWow64FlagsInformation`

Reserved for system use.

### `KeyControlFlagsInformation`

Reserved for system use.

### `KeySetVirtualizationInformation`

Reserved for system use.

### `KeySetDebugInformation`

Reserved for system use.

### `KeySetHandleTagsInformation`

Reserved for system use.

### `KeySetLayerInformation`

### `MaxKeySetInfoClass`

This member constant is always the maximum value in the enumeration.

## Remarks

A [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can receive a pointer to a **KEY_SET_INFORMATION_CLASS** structure as an input parameter.

## See also

[KEY_WRITE_TIME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_write_time_information)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)