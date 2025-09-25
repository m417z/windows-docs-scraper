## Description

Gets the current status of an async call associated with the provided context.

## Parameters

### `Handle`

The async call context to get status for.

## Return value

When complete, returns the status of the async request. If the function succeeded, SspiGetAsyncCallStatus will return **SEC_E_OK**. Otherwise, refer to the respective API called to see return error codes and their respective descriptions.

Until the call is completed, status is **SEC_I_ASYNC_CALL_PENDING**.

## Remarks

## See also

[SspiAcceptSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacceptsecuritycontextasync)

[SspiAcquireCredentialsHandleAsyncA](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacquirecredentialshandleasynca)

[SspiAcquireCredentialsHandleAsyncW](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiacquirecredentialshandleasyncw)

[SspiDeleteSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspideletesecuritycontextasync)

[SspiFreeAsyncContext](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreeasynccontext)

[SspiFreeCredentialsHandleAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspifreecredentialshandleasync)

[SspiInitializeSecurityContextAsyncA](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasynca)

[SspiInitializeSecurityContextAsyncW](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiinitializesecuritycontextasyncw)