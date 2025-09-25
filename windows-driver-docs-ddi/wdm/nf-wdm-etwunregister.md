## Description

The **EtwUnregister** function unregisters the event provider and must be called before the provider exits.

## Parameters

### `RegHandle` [in]

A pointer to the provider registration handle, which is returned by the **EtwRegister** function if the event provider registration is successful.

## Return value

The **EtwUnregister** function returns a status code of STATUS_SUCCESS if the event provider was successfully unregistered with ETW.

## Remarks

After tracing is complete, a driver must call the **EtwUnregister** function to unregister the provider. For every call to **EtwRegister** there must be a corresponding call to **EtwUnregister**. Failure to unregister the event provider can cause errors when the process is unloaded because the callbacks associated with the process are no longer valid. No tracing calls should be made that fall outside of the code bounded by the **EtwRegister** and **EtwUnregister** functions. For the best performance, you can call the **EtwRegister** function in your **DriverEntry** routine and the **EtwUnregister** function in your **DriverUnload** routine.

Callers of **EtwRegister** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[EtwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwregister)