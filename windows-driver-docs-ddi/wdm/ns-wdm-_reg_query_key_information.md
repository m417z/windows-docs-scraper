# _REG_QUERY_KEY_INFORMATION structure

## Description

The **REG_QUERY_KEY_INFORMATION** structure describes the metadata that is about to be queried for a key.

## Members

### `Object`

A pointer to the registry key object for the key whose metadata is about to be queried.

### `KeyInformationClass`

The [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class) value that indicates the type of information to be returned by the system.

### `KeyInformation`

A pointer to a buffer that contains the information to be returned by the system. The format of the buffer depends on the value of **KeyInformationClass**. For more information see [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class).

### `Length`

Specifies the size, in bytes, of the **KeyInformation** buffer.

### `ResultLength`

Pointer to a variable that receives (from the system) the amount of valid data, in bytes, in the **KeyInformation** buffer.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to query the metadata for a key—for example, when a user-mode thread calls **RegQueryInfoKey** or when a driver calls [ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)