# GetEnlistmentId function

## Description

Obtains the identifier (ID) for the specified enlistment.

## Parameters

### `EnlistmentHandle` [in]

A handle to the enlistment.

### `EnlistmentId` [out]

A pointer to a variables that receives the ID of the enlistment.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)