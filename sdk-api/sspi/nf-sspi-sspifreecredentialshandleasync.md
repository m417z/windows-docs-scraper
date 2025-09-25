## Description

Frees up a credential handle.

## Parameters

### `AsyncContext`

The async call context.

### `phCredential`

The credential handle to free.

## Return value

Returns **SEC_E_OK** if the async request to free the credential handle was successfully queued for execution. Otherwise, it returns the error generated attempting to queue it. To retrieve the status of the operation, use [SspiGetAsyncCallStatus](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspigetasynccallstatus).

SspiGetAsyncCallStatus returns **SEC_E_OK** on completion. Otherwise, it may return **SEC_I_ASYNC_CALL_PENDING** if the call is still in progress.

## Remarks

## See also

[FreeCredentialsHandle](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-freecredentialshandle)