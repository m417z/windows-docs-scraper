# WsWriteEnvelopeEnd function

## Description

Writes the closing elements of a message.
This function writes the end of the message including the element that closes the body
tag and the envelope tag.
Use this function when writing messages to destinations other than channels. With
channels use [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend)

## Parameters

### `message` [in]

A pointer to the **Message** object to write. The pointer must reference a valid [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) object.

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

To use this function the message state must be set to **WS_MESSAGE_STATE_WRITING**. If called in the correct
state the message will transition to **WS_MESSAGE_STATE_DONE** regardless
of whether the function fails or not.