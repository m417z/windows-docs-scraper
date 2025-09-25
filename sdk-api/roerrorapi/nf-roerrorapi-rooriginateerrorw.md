# RoOriginateErrorW function

## Description

Reports an error and an informative string to an attached debugger.

## Parameters

### `error` [in]

Type: **HRESULT**

The error code associated with the error condition. If *error* is a success code, such as **S_OK**, the function has no effect and returns **FALSE**. This behavior enables calling the function when no error has occurred without causing an unwanted error message.

### `cchMax` [in]

Type: **UINT**

The maximum number of characters in *message*, excluding the terminating **NUL** character. If the value is 0, the string is read to the first **NUL** character or 512 characters, whichever is less. If *cchMax* is greater than 512, all characters after 512 are ignored.

### `message` [in]

Type: **PCWSTR**

An informative string to help developers to correct the reported error condition. The maximum length is 512 characters, including the trailing **NUL** character; longer strings are truncated.

If the string is empty, the function succeeds but no error information is reported. It is recommended that you always provide an informative string.

If *message* is **NULL**, the function succeeds and reports the generic string in Winerror.h if available or the generic string associated with **E_FAIL**.

This function does not support embedded **NUL** characters, so only the characters before the first **NUL** are reported.

The *message* string should be localized.

## Return value

Type: **BOOL**

| Return code | Description |
| --- | --- |
| **TRUE** | The error message was reported successfully. |
| **FALSE** | *message* is **NULL** or points to an empty string, or *error* is a success code. |

## Remarks

Use the **RoOriginateErrorW** function to report an error condition and a corresponding message to a debugger. This function does not perform logging or event tracing.

The error is communicated to the debugger by raising a structured exception. This exception is caught by the attached debugger, and the exception parameters contain both the error and the *message* string. The debugger may display these parameters to the user.

Depending on the current configuration of the debugger, the **RoOriginateErrorW** function may cause execution to halt in the debugger at the site of the exception.

 If the **UseSetErrorInfo** flag is set by calling the [RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags) function, and the calling thread has been initialized in COM, the function creates an appropriate error object that supports [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) and associates it with the COM channel by calling [SetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-seterrorinfo). If the thread has not been initialized into COM, the call will still succeed with no error, but the error will not be associated with the COM channel.

**Note** This is no ANSI version of the **RoOriginateErrorW** function. Message strings are required to be Unicode.

## See also

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoGetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoTransformErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror)