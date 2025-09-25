# AuxUlibIsDLLSynchronizationHeld function

## Description

Determines whether the caller is holding a synchronization primitive. This information can be used to avoid operations that could potentially lead to deadlocks.

## Parameters

### `SynchronizationHeld` [out]

Indicates whether the caller is holding a synchronization primitive.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You must call the [AuxUlibInitialize](https://learn.microsoft.com/windows/desktop/api/aux_ulib/nf-aux_ulib-auxulibinitialize) function before calling this function.