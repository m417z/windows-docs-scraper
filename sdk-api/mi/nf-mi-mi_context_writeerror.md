# MI_Context_WriteError function

## Description

Sends an error code and error message to the client.

## Parameters

### `context` [in]

Request context.

### `resultCode`

Result code to send to the client.

### `resultType`

A null-terminated string that represents the type of the result code, which may (but is not required to) contain one of these values:

#### MI_RESULT_TYPE_MI ("MI")

MI result type.

#### MI_RESULT_TYPE_HRESULT ("HRESULT")

**HRESULT** (COM return type) result type.

#### MI_RESULT_TYPE_WIN32 ("WIN32")

Win32 result type. See [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

### `errorMessage`

A null-terminated string that represents the error message to accompany the result code. This message should be localized based on the client's locale request (retrieved through the [MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale) function).

### `flag` [out]

On return, flag contains **MI_TRUE** if provider should continue execution. Otherwise, the returned value will be **MI_FALSE**.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The operation is not terminated by this call, although the client has the option to indicate that the operation should be continued or canceled.

If the client does not ask for **MI_Context_WriteError** messages, the function will give an automatic response.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale)

[MI_Context_PostError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_posterror)