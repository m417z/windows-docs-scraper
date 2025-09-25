# WS_CHANNEL_STATE enumeration

## Description

The different states that a channel can be in.

## Constants

### `WS_CHANNEL_STATE_CREATED:0`

### `WS_CHANNEL_STATE_OPENING:1`

### `WS_CHANNEL_STATE_ACCEPTING:2`

### `WS_CHANNEL_STATE_OPEN:3`

### `WS_CHANNEL_STATE_FAULTED:4`

### `WS_CHANNEL_STATE_CLOSING:5`

### `WS_CHANNEL_STATE_CLOSED:6`

## Remarks

The following are the state transitions for a channel.

:::image type="content" source="./images/ChannelStates.png" border="false" alt-text="Diagram of the state transitions for a Channel object. A second diagram shows the Sub-states for the Channel's Open state.":::

A channel may move to the **WS_CHANNEL_STATE_FAULTED**
state even if [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) was never called.
This will only occur if the channel can no longer be used.

Note that only the valid state transitions are shown. Using
a function not shown for a given state will result in an
**WS_E_INVALID_OPERATION** error being returned from
the function (or crash in the case of [WsFreeChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel)).
For information on error codes, see[Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).