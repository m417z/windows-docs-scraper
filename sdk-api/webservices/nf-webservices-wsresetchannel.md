# WsResetChannel function

## Description

Reset a channel so it can be reused.

## Parameters

### `channel` [in]

The channel to reset.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The channel was in an inappropriate state. |

## Remarks

Reusing a channel instead of creating one from scratch may improve performance.

This function is only valid when the channel is in the either the
[WS_CHANNEL_STATE_CREATED](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) or **WS_CHANNEL_STATE_CLOSED** state.

If called correctly, this function will not fail (for example, due to lack of system resources).