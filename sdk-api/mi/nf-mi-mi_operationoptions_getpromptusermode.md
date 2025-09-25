# MI_OperationOptions_GetPromptUserMode function

## Description

Gets the value that tells the server how to respond to a provider's call to
[MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser).

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `mode` [out]

The returned [MI_CallbackMode](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_callbackmode) enumeration value: either MI_CALLBACKMODE_REPORT or MI_CALLBACKMODE_INQUIRE.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_CallbackMode](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_callbackmode)

[MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser)

[MI_OperationOptions_GetForceFlagPromptUserMode](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449233(v=vs.85))

[MI_OperationOptions_SetForceFlagPromptUserMode](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh449249(v=vs.85))

[MI_OperationOptions_SetPromptUserMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_setpromptusermode)