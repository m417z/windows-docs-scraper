# MI_OperationOptions_SetPromptUserRegularMode function

## Description

Sets the value that tells the server how to respond to a provider's call to
the [MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser) function.

## Parameters

### `options` [in, out]

A [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure containing a set of operation options.

### `mode` [in]

The returned [MI_CallbackMode](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_callbackmode) enumeration value: either **MI_CALLBACKMODE_REPORT** or **MI_CALLBACKMODE_INQUIRE**.

### `ackValue` [in]

TBD

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.