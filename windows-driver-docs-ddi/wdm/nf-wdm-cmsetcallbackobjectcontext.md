# CmSetCallbackObjectContext function

## Description

The **CmSetCallbackObjectContext** routine associates new context information with a specified registry object and callback routine.

## Parameters

### `Object` [in, out]

A pointer to the registry key object that the driver is providing context information for. The driver obtains this pointer from the **ResultObject** member of one of the following structures:

- [REG_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information)

- [REG_CREATE_KEY_INFORMATION_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1)

- REG_OPEN_KEY_INFORMATION

- REG_OPEN_KEY_INFORMATION_V1

### `Cookie` [in]

A pointer to a LARGE_INTEGER value that identifies the callback routine to associate the context with. The [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) routine provided this value when you registered the callback routine.

### `NewContext` [in]

A pointer to driver-defined context information.

### `OldContext` [out, optional]

A pointer to a location that receives a pointer to context information that the driver previously associated with the specified object and cookie. This parameter is optional and can be **NULL**.

## Return value

**CmSetCallbackObjectContext** returns STATUS_SUCCESS or another appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)-typed value.

## Remarks

The **CmSetCallbackObjectContext** routine is available starting with Windows Vista.

A driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can call **CmSetCallbackObjectContext** for any registry key object after the object has been created or opened (that is, during a post-notification for a create operation, an open operation, or any subsequent notification up to the pre-notification of handle closure).

If a driver calls **CmSetCallbackObjectContext**, the driver's *RegistryCallback* routine will receive a **RegNtCallbackObjectContextCleanup** notification after the key object's handle has been closed or after the driver calls [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback) to unregister the *RegistryCallback* routine. When the *RegistryCallback* routine receives this notification, the routine should release any resources that it allocated for the object's context.

If **CmSetCallbackObjectContext** is called before **RegNtCallbackObjectContextCleanup** notification, *OldContext* can still be referred by *RegistryCallback* which receives another notification. *OldContext* should not be released before **RegNtCallbackObjectContextCleanup** notification.

For more information about **CmSetCallbackObjectContext** and filtering registry operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[REG_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information)

[REG_CREATE_KEY_INFORMATION_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)