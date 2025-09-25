# WsFreeListener function

## Description

Releases the memory resource associated with a Listener object.
The Listener state represented in [WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state) must be set to either **WS_LISTENER_STATE_CREATED**
or **WS_LISTENER_STATE_CLOSED** to be released.
If a Listener has been successfully opened, then it must be closed
using [WsCloseListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloselistener) before it is released.

## Parameters

### `listener` [in]

A pointer to the **Listener** object to release. The pointer must reference a valid [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) returned
by [WsCreateListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatelistener). The referenced value may not be **NULL**.