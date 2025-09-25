# ExNotifyCallback function

## Description

The **ExNotifyCallback** routine causes all callback routines registered for the given object to be called.

## Parameters

### `CallbackObject` [in]

A pointer to the callback object for which all registered callback routines will be called.

### `Argument1` [in, optional]

Specifies the parameter that is passed as *Argument1* of the callback routine.

### `Argument2` [in, optional]

Specifies the parameter that is passed as *Argument2* of the callback routine.

## Remarks

Driver writers must not call **ExNotifyCallback** for any of the system-defined callback objects listed in **ExCreateCallback**.

The system calls callback routines in order of their registration.

For more information about callback objects, see [Callback Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/callback-objects).

Callers of this routine must be running at IRQL <= DISPATCH_LEVEL. The system calls all registered callback routines at the caller's IRQL.

## See also

[ExCreateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatecallback)

[ExRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exregistercallback)