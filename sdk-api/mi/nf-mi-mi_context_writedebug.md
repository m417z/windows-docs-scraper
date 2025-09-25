# MI_Context_WriteDebug function

## Description

Sends a debug message to the client.

## Parameters

### `context` [in]

Request context

### `message`

A null-terminated string that represents the debug message to send to the client. Localizing the message is optional, but recommended.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

A provider calls this function when a debug message needs to be sent to the client. Debug messages can be useful in determining why a given action is not completing successfully. A client can optionally register to receive these messages via an asynchronous callback. If a client does not register for these messages, the server will ignore the message.