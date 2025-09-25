# WsRemoveMappedHeader function

## Description

Removes all instances of a mapped header from the message.

## Parameters

### `message` [in]

The message to set the header in.

The message can be in any state but [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `headerName` [in]

The name of the mapped header to remove.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more of the parameters are incorrect. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

A message may contain additional transport-specific information that is
not part of the message envelope. This transport-specific information
can be exposed programmatically as headers of the Message object.
This function is used to remove mapped headers from the message object.
This can be used by a custom channel implementation to remove mapped headers
prior to sending the message.