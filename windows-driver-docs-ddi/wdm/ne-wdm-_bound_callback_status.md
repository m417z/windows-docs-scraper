# _BOUND_CALLBACK_STATUS enumeration

## Description

The **BOUND_CALLBACK_STATUS** enumeration indicates how a user-mode bounds exception was processed by the [BoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-bound_callback) function.

## Constants

### `BoundExceptionContinueSearch`

The bounds exception was not handled by the callback, and the exception should continue to propagate.

### `BoundExceptionHandled`

The exception was handled by the callback, and the exception should not propagate any further.

### `BoundExceptionError`

The user mode process should be terminated by the system.

### `BoundExceptionMaximum`

This value is not currently used.

## Remarks

The return value of the [BoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-bound_callback) routine is a **BOUND_CALLBACK_STATUS** value.

## See also

[BoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-bound_callback)