# _REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION structure

## Description

The **REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION** structure contains information that a driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use to free resources that the driver previously allocated for the context that is associated with a registry object.

## Members

### `Object`

A pointer to the registry key object for the key to be deleted.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext).

### `Reserved`

This member is reserved for future use.

## Remarks

This structure is used by the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine. When the *Argument1* parameter to the *RegistryCallback* routine is **RegNtCallbackObjectContextCleanup**, the *Argument2* parameter is a pointer to a **REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION** structure.

The driver's *RegistryCallback* routine will receive a **RegNtCallbackObjectContextCleanup** notification when the key object's reference count drops to zero (i.e. there are no outstanding handles or pointer references to the key object).

In response to this notification, the routine should release any resources that it allocated for the object's context. The **RegNtCallbackObjectContextCleanup** notification occurs when the driver has called [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback) or the driver's *RegistryCallback* routine has just finished processing a **RegNtPreKeyHandleClose** notification.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)