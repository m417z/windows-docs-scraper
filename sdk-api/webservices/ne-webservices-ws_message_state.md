# WS_MESSAGE_STATE enumeration

## Description

The different states that a message can be in.

## Constants

### `WS_MESSAGE_STATE_EMPTY:1`

The initial state after a message has been created.
In this state, there is no content in the message, and
neither the header nor the body can be accessed.

### `WS_MESSAGE_STATE_INITIALIZED:2`

The message headers have been initialized, and
can be accessed, but the body cannot be accessed. This state
is used to build up all the headers prior to writing/sending them.

### `WS_MESSAGE_STATE_READING:3`

The body of the message is being read, for example
when a message is received.
In this state, the headers can be accessed, and the body can
be read (see [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody) or
[WS_MESSAGE_PROPERTY_BODY_READER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)).

### `WS_MESSAGE_STATE_WRITING:4`

The body of the message is being written, for example
when a message is being sent.
In this state, the headers can be accessed, and the body can
be written (see [WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody) or
[WS_MESSAGE_PROPERTY_BODY_WRITER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)).

### `WS_MESSAGE_STATE_DONE:5`

The message body has been read or written (the end of the
body has been read or written). The headers can still be accessed.

## Remarks

A message object transitions through a set of states as it
is being received or sent (or read or written).

The following are the state transitions while writing or sending:

:::image type="content" source="./images/MessageSendStates.png" border="false" alt-text="Diagram of the valid state transitions for a Message object as it is being written or sent.":::

The following are the state transitions while reading or receiving:

:::image type="content" source="./images/MessageReceiveStates.png" border="false" alt-text="Diagram of the valid state transitions for a Message object as it is being read or received.":::

Note that in the above diagrams, only valid transitions are
shown.