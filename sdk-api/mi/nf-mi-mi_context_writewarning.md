# MI_Context_WriteWarning function

## Description

Writes a warning message to the client.

## Parameters

### `context` [in]

Request context

### `message`

A null-terminated string representing a warning message to send to client. This string should be localized.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Warning messages should warn of exceptional circumstances. The client can optionally register to receive these messages via an asynchronous callback. If a client does not register for these messages, the server will ignore the message.