# MI_OperationOptions_SetWriteErrorMode function

## Description

Sets the error reporting mode.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `mode` [in]

One of the following [MI_CallbackMode](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_callbackmode) values.

#### MI_CALLBACKMODE_REPORT (0)

Prompt will be passed back to the client in reporting mode, meaning the client is notified of the prompt but cannot respond to it and the server will automatically confirm the request.

#### MI_CALLBACKMODE_INQUIRE (1)

Provider will block while the client is called back to ask if the operation should continue or not.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.