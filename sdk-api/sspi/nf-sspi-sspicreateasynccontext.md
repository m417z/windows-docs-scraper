## Description

Creates an instance of SspiAsyncContext that tracks the async call.

## Return value

Returns the initialized SspiAsyncContext.

## Remarks

When done, the caller must free the async context with [SspiFreeAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreeasynccontext)

While the instance's lifetime is the single async operation, it can be reused by calling [SspiReinitAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspireinitasynccontext) after the operation has completed.

## See also

[SspiFreeAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreeasynccontext)

[SspiReinitAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspireinitasynccontext)