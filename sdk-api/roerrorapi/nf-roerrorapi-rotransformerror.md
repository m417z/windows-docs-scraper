# RoTransformError function

## Description

Reports a modified error and an informative string to an attached debugger.

## Parameters

### `oldError` [in]

Type: **HRESULT**

The original error code associated with the error condition.

### `newError` [in]

Type: **HRESULT**

A different error code to associate with the error condition. If *oldError* and *newError* are the same, or both are success codes, such as **S_OK**, the function has no effect and returns **FALSE**.

### `message` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

An informative string to help developers to correct the reported error condition. The maximum length is 512 characters, including the trailing null character; longer strings are truncated.

If the string is empty, the function succeeds but no error information is reported. It is recommended that you always provide an informative string.

If *message* is **NULL**, the function succeeds and reports the generic string in Winerror.h if available or the generic string associated with E_FAIL.

Although the *message* string is an [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring), the **RoTransformError** function does not support embedded null characters, so only the characters before the first null are reported.

## Return value

Type: **BOOL**

| Return code | Description |
| --- | --- |
| **TRUE** | The error message was reported successfully. |
| **FALSE** | *message* is **NULL** or points to an empty string, or *oldError* and *newError* are the same, or both are success codes. |

## Remarks

Use the **RoTransformError** function to substitute a custom error code for an existing error condition. For example, if the current error condition is **E_FAIL**, you can substitute a more specific error code, such as **E_FILENOTFOUND**, and report the transformed error to an attached debugger.

The behavior of the **RoTransformError** function is otherwise the same as the [RoTransformErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerrorw) function.

 If the **UseSetErrorInfo** flag is set by calling the [RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags) function, and the calling thread has been initialized in COM, the function creates an appropriate error object that supports [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) and associates it with the COM channel by calling [SetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-seterrorinfo). If the thread has not been initialized into COM, the call will still succeed with no error, but the error will not be associated with the COM channel.

## See also

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoGetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoTransformErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerrorw)