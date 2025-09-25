# _REG_ENUMERATE_VALUE_KEY_INFORMATION structure

## Description

The **REG_ENUMERATE_VALUE_KEY_INFORMATION** structure describes one value entry of a key whose value entries are being enumerated.

## Members

### `Object`

A pointer to the registry key object for the key whose value entries are being enumerated.

### `Index`

The zero-based index of the subkey within the key.

### `KeyValueInformationClass`

The [KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class) value that indicates the type of information to be returned by the system in the **KeyValueInformation** buffer.

### `KeyValueInformation`

A pointer to a buffer that contains the information to be returned by the system. The format of the buffer depends on the value of **KeyValueInformationClass**. For more information see [KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class).

### `Length`

The size, in bytes, of the **KeyValueInformation** buffer.

### `ResultLength`

A pointer to a variable that receives (from the system) the amount of valid data, in bytes, in the **KeyValueInformation** buffer.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to enumerate a value entry of a key—for example, when a user-mode thread calls **RegEnumValue** or when a driver calls [ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[ZwEnumerateValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratevaluekey)