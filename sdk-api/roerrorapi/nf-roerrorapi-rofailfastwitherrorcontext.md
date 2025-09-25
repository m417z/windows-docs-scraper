# RoFailFastWithErrorContext function

## Description

Raises a non-continuable exception in the current process.

## Parameters

### `hrError` [in]

The **HRESULT** associated with the current error. The exception is raised for any value of *hrError*.

## Remarks

The **RoFailFastWithErrorContext** function raises a non-continuable exception in the current process when an unhandled failure is encountered, which prevents the process from continuing execution in an undefined state.

Call the **RoFailFastWithErrorContext** function when a failure occurs in a completion delegate for a completed asynchronous operation, or when a failure occurs in an event handler when an event is raised.

The process that calls **RoFailFastWithErrorContext** is terminated by a call to [RaiseFailFastException](https://learn.microsoft.com/previous-versions/dd408166(v=vs.85)). The function does not validate the parameters and raises an exception for any value of the inputs.

Call the [RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext) function to save an [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) object that's associated with the current thread. The **RoFailFastWithErrorContext** function uses this contextual information to report the error call stack to the Windows Error Reporting service (WER), if it's enabled.

## See also

[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)

[RaiseFailFastException](https://learn.microsoft.com/previous-versions/dd408166(v=vs.85))

[RoCaptureErrorContext](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rocaptureerrorcontext)