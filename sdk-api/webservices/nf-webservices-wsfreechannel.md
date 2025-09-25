# WsFreeChannel function

## Description

Releases the memory resource associated with a Channel object.
The **Channel** must be in the either the [WS_CHANNEL_STATE_CREATED](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) or **WS_CHANNEL_STATE_CLOSED** state to be released. If a Channel has been successfully opened it must be closed before it can be released.

## Parameters

### `channel` [in]

A pointer to the **Channel** object to release. The pointer must reference a valid [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) object returned by [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener). The referenced value may not be **NULL**.

## Remarks

A channel that is in the process of being accepted/opened cannot be released until the accept/open completes. Use [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) to cancel the accept/open process.