# RoOriginateLanguageException function

## Description

Reports an error, an informative string, and an error object to an attached debugger.

## Parameters

### `error` [in]

The error code associated with the error condition. If *error* is a success code, like **S_OK**, the function has no effect and returns **FALSE**. This behavior enables calling the function when no error has occurred without causing an unwanted error message.

### `message` [in, optional]

An informative string to help developers to correct the reported error condition. The maximum length is 512 characters, including the trailing **NUL** character; longer strings are truncated.

If the string is empty, the function succeeds but no error information is reported. It is recommended that you always provide an informative string.

If *message* is **NULL**, the function succeeds and reports the generic string in Winerror.h if available or the generic string associated with **E_FAIL**.

This function does not support embedded **NUL** characters, so only the characters before the first **NUL** are reported.

The *message* string should be localized.

### `languageException` [in]

An error object that's apartment-agile, in-proc, and marshal-by-value across processes. This object should implement [ILanguageExceptionStackBackTrace](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionstackbacktrace) and [ILanguageExceptionTransform](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptiontransform) if necessary.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The error message was reported successfully. |
| **FALSE** | *message* is **NULL** or points to an empty string, or *error* is a success code. |

## Remarks

The **RoOriginateLanguageException** function behaves like [RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror) but takes another parameter that stores extra information about the error. Language projections use this function to store exception information alongside the COM error information. Language projections need to create an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) object that contains all the information necessary recreate it the exception a later point.

The error object must be apartment-agile, in-proc, and marshal-by-value across processes. The reason for this restriction is that the thread from which the error object is originated may no longer exist, for example due to a [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) call, by the time the error information is retrieved.

## See also

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)