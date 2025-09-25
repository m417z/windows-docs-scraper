# _REG_DELETE_KEY_INFORMATION structure

## Description

The **REG_DELETE_KEY_INFORMATION** structure contains information that a driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use when a registry key is being deleted.

## Members

### `Object`

A pointer to the registry key object for the key to be deleted.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes this structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to delete a key—for example, when a user-mode thread calls **RegDeleteKey** or **RegDeleteKeyEx** or when a driver calls [ZwDeleteKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwdeletekey).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[ZwDeleteKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwdeletekey)