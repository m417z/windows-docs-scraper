# WS_MESSAGE_DESCRIPTION structure

## Description

The schema for the input/output [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) for a given operation description.

## Members

### `action`

The action associated with the respective input/output [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message).

If the message does not have an action, this field can be **NULL**.

### `bodyElementDescription`

The description of the value within the body of the [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message).

If **NULL**, then the message body is assumed to be empty.

If non-**NULL**, this value is read or written as described in
[WsWriteBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebody) and [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody).