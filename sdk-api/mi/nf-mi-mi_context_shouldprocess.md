# MI_Context_ShouldProcess function

## Description

Queries the client to determine if an operation should continue.

## Parameters

### `context` [in]

Request context.

### `target`

A null-terminated string that represents the target of the action that is being processed. The string should be in the user's requested locale (retrieved through the [MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale) function).

### `action`

A null-terminated string that represents the action that is being processed. The string should be in the user's requested locale (retrieved through the [MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale) function).

### `flag` [out]

Boolean response from client indicating if the provider should continue processing. **MI_TRUE** indicates that the process should continue. **MI_FALSE** indicates that processing should stop.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

If the client has an auto-result specified, then the message will be reported, but the function will not wait. If the client is not interested in this function, then the function will return immediately with the default response. Otherwise, the function will not return until after the client has responded.

An example use of this function would be when deleting a file. In such a case, you might specify an *action* parameter of "deleting file" and a *target* parameter containing the name of the file to be deleted.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale)

[MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser)

[MI_Context_ShouldContinue](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_shouldcontinue)