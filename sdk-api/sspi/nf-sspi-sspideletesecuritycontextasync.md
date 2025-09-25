## Description

The **SspiDeleteSecurityContextAsync** function deletes the local data structures associated with the specified [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) initiated by a previous call to the [SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca) function or the [SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync) function.

## Parameters

### `AsyncContext`

The async call context.

### `phContext`

Handle of the security context to delete.

## Return value

Returns **SEC_E_OK** if the async request to delete the security context was successfully queued for execution. Otherwise, it returns the error generated attempting to queue it. To retrieve the status of the operation, use [SspiGetAsyncCallStatus](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspigetasynccallstatus).

SspiGetAsyncCallStatus returns **SEC_E_OK** on completion. Otherwise, it may return **SEC_I_ASYNC_CALL_PENDING** if the call is still in progress, or one of the error codes below.

|

Return code

|

Description

|
|---|---|
|**SEC_E_INVALID_HANDLE**|The handle passed to the function is not valid.|

## Remarks

On async call completion, callers can choose to opt out of receiving a notification by avoiding setting a callback for a new SspiAsyncContext or by removing the callback using [SspiSetAsyncNotifyCallback](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspisetasyncnotifycallback) with a null parameter. If opting out, the caller should free the context with [SspiFreeAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreeasynccontext) immediately after calling SspiDeleteSecurityContextAsync, unless the context is intended for reuse.

The **SspiDeleteSecurityContextAsync** function terminates a security context and frees associated resources.

The caller must call this function for a security context when that security context is no longer needed. This is true if the security context is partial, incomplete, rejected, or failed. After the security context is successfully deleted, further use of that security context is not permitted and the handle is no longer valid.

## See also

[DeleteSecurityContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-deletesecuritycontext)

[SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync)

[SspiFreeAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreeasynccontext)

[SspiInitializeSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca)

[SspiSetAsyncNotifyCallback](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspisetasyncnotifycallback)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)