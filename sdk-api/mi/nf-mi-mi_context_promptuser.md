# MI_Context_PromptUser function

## Description

Sends a prompt message to the client querying whether to continue the operation or cancel it.

## Parameters

### `context` [in]

Request context.

### `message` [in]

A null-terminated string that represents the prompt message for the client.

### `promptType`

Prompt type as defined by [MI_PromptType](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_prompttype). The
provider should try to use the locale that the client has specified (retrieved through the
[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale) function).

### `flag` [out]

Return value from the client. **MI_TRUE** indicates that the process should continue.
**MI_FALSE** indicates that the process should stop, and the provider should post some
final error to say that the operation was cancelled.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the
function return code. This can be one of the following codes.

## Remarks

If the client has an auto-result specified, then the message will be reported, but the function will not wait.
If the client is not interested in this function, then the function will return immediately with the default
response. Otherwise, the function will not return until after the client has responded to the prompt.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale)

[MI_Context_ShouldContinue](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_shouldcontinue)

[MI_Context_ShouldProcess](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_shouldprocess)

[MI_PromptType](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_prompttype)