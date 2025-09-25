# _REG_QUERY_KEY_NAME structure

## Description

The **REG_QUERY_KEY_NAME** structure describes the full registry key name
of an object being queried.

## Members

### `Object`

A pointer to the registry key object for the key whose metadata is about to be queried.

### `ObjectNameInfo`

A pointer to an **OBJECT_NAME_INFORMATION** structure (see wdm.h) that contains the full registry key name to be returned by the system, as a Unicode string.

### `Length`

Specifies the size, in bytes, of the **ObjectNameInfo** buffer.

### `ReturnLength`

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). It contains the key context for the key that is being queried.

### `Reserved`

This member is reserved for future use.

## Remarks

The system passes this structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to query the full name of the registry key.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[REG_NOTIFY_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_reg_notify_class)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)