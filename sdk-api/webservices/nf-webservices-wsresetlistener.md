# WsResetListener function

## Description

Resets a Listener object so it can be reused.
Use of this function requires that the Listener state be set to **WS_LISTENER_STATE_CREATED** or **WS_LISTENER_STATE_CLOSED**.

## Parameters

### `listener` [in]

A pointer to the **Listener** object to reset. The pointer must reference a valid [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener).

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The listener was in an inappropriate state. |

## Remarks

Before reusing a listener, this function should be called.