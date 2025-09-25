# KeRegisterBoundCallback function

## Description

The **KeRegisterBoundCallback** routine registers a routine to be called whenever a user-mode bound exception occurs.

## Parameters

### `CallbackRoutine` [in]

Pointer to a [BoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-bound_callback) function.

## Return value

On success, **KeRegisterBoundCallback** returns an opaque pointer that the caller passes to [KeDeregisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterboundcallback) to deregister the callback. The routine returns **NULL** if it is unable to register the callback.

## Remarks

The **KeRegisterBoundCallback** routine provides the opportunity for a kernel-mode driver to intercept and handle user-mode bound exceptions. When a bounds exception for a user-mode thread occurs, the system calls the registered [BoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-bound_callback) function to manage the bounds trap. The return value of the *BoundCallback* function indicates the action that the system should then perform, such as propagating the bounds exception or terminating the user-mode process.

## See also

[KeDeregisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterboundcallback)