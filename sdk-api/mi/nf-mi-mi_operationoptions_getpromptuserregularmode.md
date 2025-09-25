# MI_OperationOptions_GetPromptUserRegularMode function

## Description

Gets the value that tells the server how to respond to a provider's call to
[MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser).

## Parameters

### `options` [in, out]

A [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure containing a set of operation options.

### `mode` [out]

The returned [MI_CallbackMode](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_callbackmode) enumeration value: either **MI_CALLBACKMODE_REPORT** or **MI_CALLBACKMODE_INQUIRE**.

### `ackValue` [out]

TBD

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.