# _REG_ENUMERATE_KEY_INFORMATION structure

## Description

The **REG_ENUMERATE_KEY_INFORMATION** structure describes one subkey of a key whose subkeys are being enumerated.

## Members

### `Object`

A pointer to the registry key object for the key whose subkeys are being enumerated.

### `Index`

The zero-based index of the subkey within the key.

### `KeyInformationClass`

The [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class) value that indicates the type of information to be returned by the system in the **KeyInformation** buffer.

### `KeyInformation`

A pointer to a buffer that contains the information to be returned by the system. The format of the buffer depends on the value of **KeyInformationClass**. For more information, see [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class).

### `Length`

The size, in bytes, of the **KeyInformation** buffer.

### `ResultLength`

A pointer to a ULONG that receives (from the system) the amount of valid data, in bytes, in the **KeyInformation** buffer.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to enumerate the subkeys of a key—for example, when a user-mode thread calls **RegEnumKey** or **RegEnumKeyEx** or when a driver calls [ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)