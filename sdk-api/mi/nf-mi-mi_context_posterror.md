# MI_Context_PostError function

## Description

Providers call this function to post a return code to the client in response to a request.

## Parameters

### `context` [in]

A pointer to the request context.

### `resultCode`

The Result code to be sent to the client.

### `resultType`

A null-terminated string that represents the type of the result code. The string can be one of these values or an arbitrary value defined by the provider.

#### MI_RESULT_TYPE_MI ("MI")

MI result type

#### MI_RESULT_TYPE_HRESULT ("HRESULT")

HRESULT (COM return type) result type

#### MI_RESULT_TYPE_WIN32 ("WIN32")

Win32 result type

### `errorMessage`

A null-terminated string that represents the error message to be sent to the client. The message should be in the requested UI locale, if possible.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

After an error is posted, the request context must not be used, because it becomes invalid at this point.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_WriteError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writeerror)