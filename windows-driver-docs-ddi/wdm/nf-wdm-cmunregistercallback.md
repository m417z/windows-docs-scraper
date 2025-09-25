## Description

The **CmUnRegisterCallback** routine unregisters a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine that a [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) routine previously registered.

## Parameters

### `Cookie` [in]

A LARGE_INTEGER value that identifies the callback routine to unregister. **CmRegisterCallback** provided this value when you registered the callback routine.

## Return value

**CmUnRegisterCallback** returns STATUS_SUCCESS if it succeeds or the appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code if it fails. If the *Cookie* parameter does not match any registered callback routines, **CmUnRegisterCallback** returns STATUS_INVALID_PARAMETER.

## Remarks

A driver that calls **CmRegisterCallback** or **CmRegisterCallbackEx** should call **CmUnRegisterCallback** before the driver is unloaded.

A driver must not call **CmUnRegisterCallback** from its implementation of the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine. That call will result in a deadlock.

For more information about **CmUnRegisterCallback** and filtering registry operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)