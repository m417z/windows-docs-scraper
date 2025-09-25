# _REG_SET_VALUE_KEY_INFORMATION structure

## Description

The **REG_SET_VALUE_KEY_INFORMATION** structure describes a new setting for a registry key's value entry.

## Members

### `Object`

A pointer to the registry key object for the key whose value entry is about to be changed.

### `ValueName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the value entry about to be changed.

### `TitleIndex`

Reserved for system use. Drivers should ignore this member.

### `Type`

The type of data that is about to be written. For more information about the possible values for this member, see the *Type* parameter of [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

### `Data`

A pointer to a buffer that contains the data about to be written. The format of the buffer depends on the value of **Type**. For more information, see [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

### `DataSize`

The size, in bytes, of the **Data** buffer.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to set a value entry for a key—for example, when a user-mode thread calls **RegSetValue** or **RegSetValueEx** or when a driver calls [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)