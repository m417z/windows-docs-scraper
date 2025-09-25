## Description

The **SspiFreeAsyncContext** function frees up a context created in the call to the [SspiCreateAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspicreateasynccontext) function.

## Parameters

### `Handle`

The async call context to free.

## Remarks

For all operations that require notification of completion, SspiFreeAsyncContext must not be called until the async operation is complete and the callback has been invoked. Calling [SspiGetAsyncCallStatus](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspigetasynccallstatus) will return status != SEC_I_ASYNC_CALL_PENDING to indicate the async operation has not completed.

## See also

[SspiCreateAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspicreateasynccontext)

[SspiGetAsyncCallStatus](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspigetasynccallstatus)