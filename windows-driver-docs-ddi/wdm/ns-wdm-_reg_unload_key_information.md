# _REG_UNLOAD_KEY_INFORMATION structure

## Description

The **REG_UNLOAD_KEY_INFORMATION** structure contains information that a driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use when a registry hive is unloaded.

## Members

### `Object`

A pointer to a registry key object. This object represents the root key of the hive that is being unloaded.

### `UserEvent`

A pointer to an event object.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined starting with Windows Vista.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined starting with Windows Vista.

### `Reserved`

This member is reserved for future use. This member is defined starting with Windows Vista.

## Remarks

This structure is used by the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine. When the *Argument1* parameter to the *RegistryCallback* routine is **RegNtPreUnloadKey**, the *Argument2* parameter is a pointer to a **REG_UNLOAD_KEY_INFORMATION** structure.

The operating system passes the **REG_UNLOAD_KEY_INFORMATION** structure to the *RegistryCallback* routine every time a thread attempts to unload a key—for example, when a user-mode thread calls the [RegUnloadKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regunloadkeya) function. In response to a **RegNtPreUnloadKey** notification, the *RegistryCallback* routine should free any resources the driver previously allocated for use with the hive before the hive is unloaded.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)