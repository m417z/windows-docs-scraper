# MI_Context_WriteVerbose function

## Description

Writes a verbose message to the client.

## Parameters

### `context` [in]

Request context.

### `message`

A null-terminated string that represents the message to be sent to the client. This string should be localized.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

A provider calls this function when a verbose message needs to be sent to the client. A verbose message indicates any progress a provider may be making or useful information that a client may need while running an operation. A client can optionally register to receive these messages via an asynchronous callback. If a client does not register for these messages, the server will ignore the message.