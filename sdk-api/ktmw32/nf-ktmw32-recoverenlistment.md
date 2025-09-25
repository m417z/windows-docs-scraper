# RecoverEnlistment function

## Description

Recovers an enlistment's state.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `EnlistmentKey` [in, optional]

The key to the enlistment to be recovered.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)