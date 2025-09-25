# _REG_SET_INFORMATION_KEY_INFORMATION structure

## Description

The **REG_SET_INFORMATION_KEY_INFORMATION** structure describes a new setting for a key's metadata.

## Members

### `Object`

A pointer to the registry key object for the key whose metadata is about to be changed.

### `KeySetInformationClass`

The [KEY_SET_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_set_information_class) value that indicates the type of information about to be changed.

### `KeySetInformation`

A pointer to a buffer that contains the information about to be written. The format of the buffer depends on the value of **KeySetInformationClass**. For more information, see [KEY_SET_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_set_information_class).

### `KeySetInformationLength`

The size, in bytes, of the **KeySetInformation** buffer.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)