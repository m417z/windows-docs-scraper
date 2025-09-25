# ObUnRegisterCallbacks function

## Description

The **ObUnRegisterCallbacks** routine unregisters a set of callback routines that were registered with the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine.

## Parameters

### `RegistrationHandle` [in]

A value that identifies the set of callback routines to unregister. The [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine provides this value when it originally registered the callback routines.

## Remarks

A driver that calls the **ObRegisterCallbacks** routine must call the **ObUnRegisterCallbacks** routine before the driver is unloaded.

> [!CAUTION]
> Do not call **ObRegisterCallbacks** more than once. This is a "double free" and results in [Bug Check 0x7E: SYSTEM_THREAD_EXCEPTION_NOT_HANDLED](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x7e--system-thread-exception-not-handled).

## See also

[ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks)