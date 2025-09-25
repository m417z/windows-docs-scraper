# RoCaptureErrorContext function

## Description

Saves the current error context so that it's available for later calls to the [RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext) function.

## Parameters

### `hr`

The **HRESULT** associated with the error.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **RoCaptureErrorContext** function captures the context associated with an error, including the stack-backtrace. This information is stored in the restricted error object and is available to the Windows Error Reporting (WER) service, if WER is enabled, and if a subsequent call is made to the [RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext) function from the same thread.

To use **RoCaptureErrorContext** function with [RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror), call **RoOriginateError** first, and then call **RoCaptureErrorContext**. Calling in the reverse order may cause the error context to be lost.

## See also

[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)

[RoFailFastWithErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoOriginateErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerrorw)