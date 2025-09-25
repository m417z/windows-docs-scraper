# MI_OperationOptions_GetWriteErrorMode function

## Description

Sets the error reporting mode.

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `mode` [out]

Returned MI_CallbackMode value.

#### MI_CALLBACKMODE_REPORT

Prompt will be passed back to the client in reporting mode, meaning the client is notified of the prompt but cannot respond to it and the server will automatically confirm the request.

#### MI_CALLBACKMODE_INQUIRE

Provider will block while the client is called back to ask if the operation should continue or not.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.