# APC_CALLBACK_DATA structure

## Description

Specifies the data for a user-mode asynchronous procedure call (APC) object.

## Members

### `Parameter`

The data passed to the function using the dwData parameter of the [QueueUserAPC](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc) function.

### `ContextRecord`

The processor context that was interrupted when the thread was directed to call the APC function.

### `Reserved0`

Reserved for future use; must be zero.

### `Reserved1`

Reserved for future use; must be zero.

## Remarks

## See also