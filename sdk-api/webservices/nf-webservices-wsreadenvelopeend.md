# WsReadEnvelopeEnd function

## Description

Reads the closing elements of a message.
The operation allows for reading of messages from sources other than Channels. If the source is a Channel use [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend).

## Parameters

### `message` [in]

A pointer to the **Message** object read. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message).

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The message state must be **WS_MESSAGE_STATE_READING**. If called in the correct
state the message state is set to **WS_MESSAGE_STATE_DONE** regardless
of function success or failure.