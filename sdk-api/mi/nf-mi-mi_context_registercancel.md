# MI_Context_RegisterCancel function

## Description

Registers a callback that is invoked when the operation is canceled.

## Parameters

### `context` [in]

Request context.

### `callback` [in]

Function that will be called if the operation is canceled.

### `callbackData` [in, optional]

Data to be passed to the callback.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

If a provider calls this function multiple times on the same context, only the last callback function will be called. Not all operations canceled on the client will reach the provider. If this is an operation that cannot register the cancellation callback, the function will return an error. This would mean the operation will run to completion. If the operation runs through to completion, the callback function will not be called.

## See also

[MI_CancelCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792316(v=vs.85))

[MI_CancellationReason](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_cancellationreason)

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)