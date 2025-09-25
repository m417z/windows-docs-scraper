# CmRegisterCallback function

## Description

The **CmRegisterCallback** routine is **obsolete** for Windows Vista and later operating system versions. Use [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) instead.

The **CmRegisterCallback** routine registers a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine.

## Parameters

### `Function` [in]

A pointer to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine to register.

### `Context` [in, optional]

A driver-defined value that the configuration manager will pass as the *CallbackContext* parameter to the *RegistryCallback* routine

### `Cookie` [out]

A pointer to a LARGE_INTEGER variable that receives the value that identifies the callback routine. When you unregister the callback routine, pass this value as the *Cookie* parameter to [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback).

## Return value

**CmRegisterCallback** returns STATUS_SUCCESS if the operation succeeds or the appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code if it fails.

## Remarks

The **CmRegisterCallback** routine is available on Windows XP and later operating system versions. For Windows Vista and later operating system versions, you should use [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) instead.

A driver calls **CmRegisterCallback** to register a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine, which is called every time a thread performs an operation on the registry.

Call [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback) to unregister a callback routine that **CmRegisterCallback** registered.

For more information about **CmRegisterCallback** and filtering registry operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)