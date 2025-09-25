# WS_LISTENER_STATE enumeration

## Description

The different states that a listener can be in.

## Constants

### `WS_LISTENER_STATE_CREATED:0`

### `WS_LISTENER_STATE_OPENING:1`

### `WS_LISTENER_STATE_OPEN:2`

### `WS_LISTENER_STATE_FAULTED:3`

### `WS_LISTENER_STATE_CLOSING:4`

### `WS_LISTENER_STATE_CLOSED:5`

## Remarks

The following are the state transitions for a Listener.

:::image type="content" source="./images/ListenerStates.png" border="false" alt-text="Diagram showing the possible states of a Listener object and the transitions between them.":::

A listener will only move to **WS_LISTENER_STATE_FAULTED**
state if [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener) is called.

Note that only the valid state transitions are shown. Using
a function not shown for a given state will result in an
**WS_E_INVALID_OPERATION** error being returned from
the function (or crash in the case of [WsFreeListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreelistener)).
See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).