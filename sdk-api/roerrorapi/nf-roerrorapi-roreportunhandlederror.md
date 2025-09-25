# RoReportUnhandledError function

## Description

Triggers the Global Error Handler when an unhandled exception occurs.

## Parameters

### `pRestrictedErrorInfo` [in]

The error to report. Call the [GetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-getrestrictederrorinfo) function to get the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) that represents the error.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **RoReportUnhandledError** function enables language projections to trigger execution of the Global Error Handler when an exception reaches the top of the stack, which normally would terminate the application.

## See also

[GetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-getrestrictederrorinfo)

[ICoreApplicationUnhandledError](https://msdn.microsoft.com/295bcf8f-c264-48d9-a460-c2a0a2fb1201)